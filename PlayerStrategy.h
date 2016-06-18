#ifndef _PLAYERSTRATEGY_
#define _PLAYERSTRATEGY_

#include "StrategyDecision.h"
#include "Card.h"

#include <istream>
#include <list>
#include <vector>

class PlayerStrategy {
public:
    StrategyDecision play(const std::list<Card*> &hand, const std::vector<Card*> &gamePile);
};

#endif
