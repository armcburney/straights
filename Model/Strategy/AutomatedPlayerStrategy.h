#ifndef _AUTO_PLAYER_STRATEGY_
#define _AUTO_PLAYER_STRATEGY_

#include <istream>
#include "PlayerStrategy.h"

class AutomatedPlayerStrategy : public PlayerStrategy {
    TurnResult play(
        std::list<CardPtr> &hand,
        const std::set<CardPtr, CardPtrComp> &gamePile,
        const Command &input) final;
};

#endif
