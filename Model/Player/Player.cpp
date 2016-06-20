#include "Player.h"
#include <iostream>
#include <algorithm>

using namespace std;

Player::Player (int id, shared_ptr<PlayerStrategy> strategy)
    : id(id),
      score(0),
      roundScore(0),
      strategy(strategy),
      hand(),
      discardPile() {}

Score Player::getScore () const {
    return score + roundScore;
}

TurnResult Player::playStrategy(set<CardPtr, CardPtrComp> &gamePile, const Command& input) {
    TurnResult turnResult = strategy->play(hand, gamePile, input);

    if (turnResult.getType() == TurnResult::PLAY) {
        // A card was played, add it to the gamePile and remove it
        // from the player's hand
        CardPtr card = turnResult.getCard();
        gamePile.insert(card);
        hand.remove(card);
    } else if (turnResult.getType() == TurnResult::DISCARD) {
        // A card was discarded, add it to the discardPile and remove it
        // from the player's hand
        CardPtr card = turnResult.getCard();
        // Add to the players score with the value of the card
        roundScore = roundScore + card->getRank() + 1;

        discardPile.push_back(card);
        hand.remove(card);
    }

    return turnResult;
}

// Clears the hand, discard pile and updates score
void Player::clearRound() {
    hand.clear();
    discardPile.clear();

    // Add this rounds score to the overall score
    score = score + roundScore;
    roundScore = 0;
}

void Player::setHand(list<CardPtr> l) {
    hand = l;
}

list<CardPtr> Player::getHand() const {
    return hand;
}

int Player::getID () const {
    return id;
}

// Returns true if the player's hand is empty
bool Player::allCardsPlayed() const {
    return hand.empty();
}

void Player::setStrategy(shared_ptr<PlayerStrategy> newStrategy) {
    strategy = newStrategy;
}

// Returns true if the player has the card
bool Player::hasCard(Card card) const {
    return any_of(
        hand.begin(),
        hand.end(),
        [card] (CardPtr c) { return *c == card; }
    );
}

ostream &operator<<(ostream &out, const Player &p) {
    out << "Player " << p.getID() << "'s discards:";
    for (CardPtr c : p.discardPile)
        out << " " << *c;
    out << endl;

    out << "Player " << p.getID() << "'s score: ";
    out << p.score << " + " << p.roundScore << " = ";
    out << p.score + p.roundScore;
    out << endl;

    return out;
}
