#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Deck.h"
#include "Player/Player.h"
#include "Player/ComputerPlayer.h"
#include "Player/HumanPlayer.h"
#include "Straights.h"

using namespace std;

Straights::Straights() : currentRound(0) {
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

/* Deals the cards to players 1 to 4 */
void Straights::deal () {
    deck.shuffle();

    // partition the vector
    for (int i = 0; i < 4; i++) {
        list<CardPtr> list(deck.cards().begin()+(i*13), deck.cards().begin()+((i+1)*13));
        players[i].setHand(list);
    }
}

/* Initiates next round */
TurnResult Straights::next (const Command &input) {
    TurnResult turnResult = currentPlayer->playStrategy(gamePile, input);

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
                [] (Player p) { return p.getScore() >= endingScore; }
            );

            if (scoreAboveEndingThreshold) {
                // --------------------------
                // The game has ended
                // --------------------------
                turnResult.setStatus(TurnResult::GAME_COMPLETE);
            }

            // Clear the table
            clearRound();
        }
    }

    return turnResult;
}

void Straights::clearRound() {
    // Clear the table
    gamePile.clear();

    // Clear each player's discard piles & hands
    for (auto &p : players) {
        p.clearRound();
    }
}

Deck Straights::getDeck() const {
    return deck;
}

vector<HandItr> Straights::getLegalPlays(list<CardPtr> hand, const vector<CardPtr> &gamePile) {
    vector<HandItr> legalPlays;
    const Card &topCard = *gamePile.back();
    for (auto it = hand.begin(); it != hand.end(); it++) {
        const Card &cardInHand = **it;
        if (cardInHand.getSuit() == topCard.getSuit() ||
                abs(cardInHand.getRank() - topCard.getRank()) <= 1)
            legalPlays.push_back(it);
    }
    return legalPlays;
}
