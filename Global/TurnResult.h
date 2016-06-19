#ifndef _TURNRESULT_
#define _TURNRESULT_

#include "../Model/Player/Player.h"
#include "../Model/Card.h"

#include <istream>
#include <memory>

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

    TurnResult(Status, Type, HandItr = HandItr(), std::shared_ptr<Player> = nullptr);

    Type getType() const;
    HandItr getCard() const;

    Status getStatus() const;
    void setStatus(Status);

    std::shared_ptr<Player> getCurrentPlayer() const;
    void setCurrentPlayer(std::shared_ptr<Player>) const;

private:
    Status status;
    const Type type;
    const HandItr card;
    std::shared_ptr<Player> currentPlayer;
};

#endif
