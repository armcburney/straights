#include "Player.h"
#include <iostream>

using namespace std;

Player::Player (int id, shared_ptr<PlayerStrategy> strategy)
    : id(id),
      score(0),
      roundScore(0),
      strategy(strategy) {}

Score Player::getScore () const {
    return score;
}

Score Player::getRoundScore () const {
    return roundScore;
}

TurnResult Player::playStrategy(vector<CardPtr> &gamePile, const Command& input) {
    TurnResult turnResult = strategy->play(hand, gamePile, input);

    if (turnResult.getType() == TurnResult::PLAY) {
        // A card was played, add it to the gamePile and remove it
        // from the player's hand
        HandItr card = turnResult.getCard();
        gamePile.push_back(*card);
        hand.erase(card);
    } else if (turnResult.getType() == TurnResult::DISCARD) {
        // A card was discarded, add it to the discardPile and remove it
        // from the player's hand
        HandItr card = turnResult.getCard();
        discardPile.push_back(*card);
        hand.erase(card);
    }

    turnResult.setCurrentPlayer(this);
    return turnResult;
}

void Player::clearRound() {
    hand.clear();
    discardPile.clear();

    // Add this rounds score to the overall score
    score += roundScore;
    lastRoundScore = roundScore;
    roundScore = 0;
}

void Player::setHand(list<CardPtr> l) {
    hand = l;
}

void Player::getHand() const {
    return hand;
}

int Player::getID () const {
    return id;
}

bool Player::allCardsPlayed() const {
    return hand.empty();
}

ostream &operator<<(ostream &out, const Player &p) {
    out << "Player " << p.getID() << "'s discards:";
    for (CardPtr c : p.discardPile)
        out << " " << *c;

    out << "Player " << p.getID() << "'s score: ";
    out << p.getScore() << " + " p.lastRoundScore << " = ";
    out << p.getScore() + p.lastRoundScore;
}
