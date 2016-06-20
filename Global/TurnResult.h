#ifndef _TURNRESULT_
#define _TURNRESULT_

#include "../Model/Card.h"

#include <istream>
#include <memory>
#include <list>

class Player;

class TurnResult {
public:
    enum Type {
        PLAY = 'p',
        DISCARD = 'd',
        REQUIRE_HUMAN_INPUT = 'i',
    };

    enum Status {
        TURN_IN_PROGRESS = 'p',
        TURN_COMPLETE = 't',
        ROUND_COMPLETE = 'r',
        GAME_COMPLETE = 'g',
    };

    TurnResult(Status, Type, CardPtr = nullptr, std::shared_ptr<Player> = nullptr);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a TurnResult with status
      and type initialized.
    */
    TurnResult(const TurnResult &);
    /*
    PRECONDITION:
      - requires: a valid TurnResult object
    POSTCONDITIONS:
      - ensures: the current object becomes a copy of the object passed in
    */
    TurnResult& operator=(TurnResult);
    /*
    POSTCONDITIONS:
      - returns: a copy of the object passed in
    */
    Type getType() const;
    /*
    POSTCONDITIONS:
      - returns: the object type
    */
    CardPtr getCard() const;
    /*
    POSTCONDITIONS:
      - returns: the object card
    */
    Status getStatus() const;
    /*
    POSTCONDITIONS:
      - returns: the object status
    */
    void setStatus(Status);
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: this.status equals the status passed in
    */
    std::shared_ptr<Player> getCurrentPlayer() const;
    /*
    POSTCONDITIONS:
      - returns: the object player
    */
    void setCurrentPlayer(std::shared_ptr<Player>);
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: this.player equals the player passed in
    */

private:
    Status status;
    Type type;
    CardPtr card;
    std::shared_ptr<Player> currentPlayer;
};

std::ostream &operator<<(std::ostream &out, const TurnResult &tr);

#endif
