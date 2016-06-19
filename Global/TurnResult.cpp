#include "TurnResult.h"

using namespace std;

TurnResult::TurnResult(Status status, Type type, HandItr card, shared_ptr<Player> currentPlayer)
    : status(status),
      type(type),
      card(card),
      currentPlayer(currentPlayer) {};


TurnResult::Type TurnResult::getType() const {
    return type;
}

HandItr TurnResult::getCard() const {
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

void TurnResult::setCurrentPlayer(shared_ptr<Player> player) const {
    currentPlayer = player;
}

// Output

ostream &operator<<(ostream &out, const TurnResult &tr){
    shared_ptr<Player> player = tr.getCurrentPlayer();
    string action;
    if (tr.getType() == TurnResult::PLAY)
        action = "plays";
    else
        action = "discards";

    out << "Player " << player->getID() << " " << action << " " << *tr.getCard() << ".";
    return out;
}
