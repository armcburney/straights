#ifndef _TURNRESULT_
#define _TURNRESULT_

#include "../Model/Card.h"

#include <istream>
#include <memory>
#include <list>

typedef std::list<CardPtr>::iterator HandItr;

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

    TurnResult(Status, Type, HandItr = HandItr(), std::shared_ptr<Player> = nullptr);
    TurnResult(const TurnResult &);
    TurnResult& operator=(TurnResult);

    Type getType() const;
    HandItr getCard() const;

    Status getStatus() const;
    void setStatus(Status);

    std::shared_ptr<Player> getCurrentPlayer() const;
    void setCurrentPlayer(std::shared_ptr<Player>);

private:
    Status status;
    Type type;
    HandItr card;
    std::shared_ptr<Player> currentPlayer;
};

std::ostream &operator<<(std::ostream &out, const TurnResult &tr);

#endif
