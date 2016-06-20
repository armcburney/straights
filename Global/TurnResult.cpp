#include "TurnResult.h"
#include "../Model/Player/Player.h"

using namespace std;

TurnResult::TurnResult(Status status, Type type, CardPtr card, shared_ptr<Player> currentPlayer)
    : status(status),
      type(type),
      card(card),
      currentPlayer(currentPlayer) {};

TurnResult::TurnResult(const TurnResult &) = default;

TurnResult& TurnResult::operator=(TurnResult r) {;
    swap(status, r.status);
    swap(type, r.type);
    swap(card, r.card);
    swap(currentPlayer, r.currentPlayer);
    return *this;
}


TurnResult::Type TurnResult::getType() const {
    return type;
}

CardPtr TurnResult::getCard() const {
    return card;
}


TurnResult::Status TurnResult::getStatus() const {
    return status;
}

void TurnResult::setStatus(Status s) {
    status = s;
}


shared_ptr<Player> TurnResult::getCurrentPlayer() const {
    return currentPlayer;
}

void TurnResult::setCurrentPlayer(shared_ptr<Player> player) {
    currentPlayer = player;
}

// Output
#include<iostream>
ostream &operator<<(ostream &out, const TurnResult &tr) {
    shared_ptr<Player> player = tr.getCurrentPlayer();
    string action;
    if (tr.getType() == TurnResult::PLAY)
        action = "plays";
    else
        action = "discards";

    out << "Player " << player->getID() << " " << action << " " << *tr.getCard() << "." << endl;
    return out;
}
