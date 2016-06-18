#ifndef _PLAYERSTRATEGY_
#define _PLAYERSTRATEGY_

#include "StrategyDecision.h"
#include "Card.h"
#include "Command.h"

#include <istream>
#include <list>
#include <vector>

class PlayerStrategy {
public:
    virtual StrategyDecision play(
        std::list<CardPtr> &hand,
        const std::vector<CardPtr> &gamePile,
        const Command &input) = 0;
};

#endif
