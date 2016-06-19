#ifndef _AUTO_PLAYER_STRATEGY_
#define _AUTO_PLAYER_STRATEGY_

#include <istream>
#include "PlayerStrategy.h"

class AutomatedPlayerStrategy : PlayerStrategy {
    TurnResult play(
        std::list<CardPtr> &hand,
        const std::vector<CardPtr> &gamePile,
        const Command &input) final;
};

#endif
