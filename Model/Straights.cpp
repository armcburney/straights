#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Deck.h"
#include "Player/Player.h"
#include "Player/ComputerPlayer.h"
#include "Player/HumanPlayer.h"
#include "Straights.h"
#include "Strategy/AutomatedPlayerStrategy.h"

#include "../Global/Subject.cpp"

using namespace std;

const Score Straights::endingScoreThreshold = Score(80);

// For using shared_ptr on statically allocated objects
struct null_deleter {
    void operator()(void const *) const {}
};

Straights::Straights(int seed) : seed_(seed) {
    currentPlayer = players.begin();
}

void Straights::addHumanPlayer (int id) {
    HumanPlayer p = HumanPlayer(id);
    players.push_back(p);
}
void Straights::addComputerPlayer (int id) {
    ComputerPlayer p = ComputerPlayer(id);
    players.push_back(p);
}

// Deals the cards to players 1 to 4
void Straights::deal () {
    deck.shuffle(seed_);

    // partition the vector
    for (int i = 0; i < 4; i++) {
        auto cards = deck.cards();
        list<CardPtr> list(cards.begin()+(i*13), cards.begin()+((i+1)*13));
        players[i].setHand(list);
    }

    currentPlayer = find_if(
        players.begin(),
        players.end(),
        [] (const Player &p) {
            return p.hasCard(Card(Card::SPADE, Card::SEVEN));
        }
    );

    notify();
}

// Initiates next round
TurnResult Straights::next (const Command &input) {
    TurnResult turnResult = currentPlayer->playStrategy(gamePile, input);
    turnResult.setCurrentPlayer(shared_ptr<Player>(&*currentPlayer, null_deleter()));

    if (turnResult.getStatus() == TurnResult::TURN_COMPLETE) {
        // After each turn, check if the round is over
        // The round is over when all cards are played
        bool allCardsPlayed = all_of(
            players.begin(),
            players.end(),
            [] (Player p) { return p.allCardsPlayed(); }
        );

        if (allCardsPlayed) {
            // --------------------------
            // This round is over
            // --------------------------
            turnResult.setStatus(TurnResult::ROUND_COMPLETE);

            // Check if score for any player is greater than
            // threshold to end game
            bool scoreAboveEndingThreshold = any_of(
                players.begin(),
                players.end(),
                [] (const Player &p) { return p.getScore() >= endingScoreThreshold; }
            );

            if (scoreAboveEndingThreshold) {
                // --------------------------
                // The game has ended
                // --------------------------
                turnResult.setStatus(TurnResult::GAME_COMPLETE);
            }
        }

        // Move to next player
        currentPlayer++;
        if (currentPlayer == players.end())
            currentPlayer = players.begin();
    }

    notify();

    return turnResult;
}

PlayerItr Straights::returnCurrentPlayer() const {
    return currentPlayer;
}

vector<Player> Straights::returnPlayers() const {
  return players;
}

// Changes the player's strategy to the AutomatedPlayerStrategy
void Straights::automateCurrentPlayer() {
    auto newStrategy = shared_ptr<PlayerStrategy>(new AutomatedPlayerStrategy);
    currentPlayer->setStrategy(newStrategy);

    notify();
}

void Straights::clearRound() {
    // Clear the table
    gamePile.clear();

    // Clear each player's discard piles & hands
    for (auto &p : players) {
        p.clearRound();
    }

    notify();
}

Deck Straights::getDeck() const {
    return deck;
}

TurnContext Straights::getTurnContext() const {
    return TurnContext(
        currentPlayer->getHand(),
        gamePile
    );
}

RoundContext Straights::getRoundContext() const {
    // Custom variables to be returned in the context
    std::vector<std::vector<TurnResult>>    playerRoundMoves;
    std::vector<Score>                      playerScores;
    std::vector<Player::Type>               playerTypes;

    // Get the values for these variables
    transform(
        players.begin(),
        players.end(),
        back_inserter(playerRoundMoves),
        [] (const Player &p) {
            return p.getRoundMoves();
        }
    );
    transform(
        players.begin(),
        players.end(),
        back_inserter(playerScores),
        [] (const Player &p) {
            return p.getScore();
        }
    );
    transform(
        players.begin(),
        players.end(),
        back_inserter(playerTypes),
        [] (const Player &p) {
            return p.getType();
        }
    );

    return RoundContext(
        players,
        currentPlayer->getID(),
        gamePile,
        playerRoundMoves,
        playerScores,
        playerTypes
    );
}

vector<CardPtr> Straights::getLegalPlays(list<CardPtr> hand, const set<CardPtr, CardPtrComp> &gamePile) {
    vector<CardPtr> legalPlays;

    // If this is the first move, then only 7S is a legal move
    if (gamePile.empty()) {
        Card sevenOfSpades = Card(Card::SPADE, Card::SEVEN);
        CardPtr firstMove = *find_if(
            hand.begin(),
            hand.end(),
            [sevenOfSpades] (CardPtr c) {
                return *c == sevenOfSpades;
            }
        );
        legalPlays.push_back(firstMove);
        return legalPlays;
    }

    for (auto it = hand.begin(); it != hand.end(); it++) {
        for (CardPtr pileCard : gamePile) {
            CardPtr cardInHand = *it;
            if ((cardInHand->getSuit() == pileCard->getSuit() &&
                    abs(cardInHand->getRank() - pileCard->getRank()) <= 1) ||
                (cardInHand->getRank() == Card::SEVEN)) {

                // Don't add the same legal play twice
                if (find(legalPlays.begin(), legalPlays.end(), cardInHand) == legalPlays.end()) {
                    legalPlays.push_back(cardInHand);
                }
            }
        }
    }
    return legalPlays;
}

void Straights::notify() {
    notifyWithContext(getRoundContext());
}

// Output
ostream &operator<<(ostream &out, const Straights &s) {
    const auto &losingPlayer = find_if(
        s.players.begin(),
        s.players.end(),
        [] (const Player &p) {
            return p.getScore() > Straights::endingScoreThreshold;
        }
    );

    if (losingPlayer != s.players.end()) {
        // We have a winner!
        const auto &winningPlayer = min_element(
            s.players.begin(),
            s.players.end(),
            [] (const Player &p1, const Player &p2) {
                return p1.getScore() < p2.getScore();
            }
        );
        out << "Player " << winningPlayer->getID() << " wins!";
    } else {
        // No winner, we're starting a new round
        out << "A new round begins. It's player " << s.currentPlayer->getID() << "'s turn to play.";
    }
    out << endl;

    return out;
}
