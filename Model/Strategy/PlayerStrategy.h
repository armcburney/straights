#ifndef _PLAYERSTRATEGY_
#define _PLAYERSTRATEGY_

#include <istream>
#include <list>
#include <set>

#include "../../Global/TurnResult.h"
#include "../../Global/Command.h"
#include "../Card.h"

class PlayerStrategy {
public:
    virtual TurnResult play(
        std::list<CardPtr> &hand,
        const std::set<CardPtr, CardPtrComp> &gamePile,
        const Command &input) = 0;
};

#endif
