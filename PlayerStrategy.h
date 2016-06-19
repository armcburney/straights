#ifndef _PLAYERSTRATEGY_
#define _PLAYERSTRATEGY_

#include "TurnResult.h"
#include "Card.h"
#include "Command.h"

#include <istream>
#include <list>
#include <vector>

class PlayerStrategy {
public:
    virtual TurnResult play(
        std::list<CardPtr> &hand,
        const std::vector<CardPtr> &gamePile,
        const Command &input) = 0;
};

#endif
