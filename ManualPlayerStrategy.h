#ifndef _MANUAL_PLAYER_STRATEGY_
#define _MANUAL_PLAYER_STRATEGY_

#include <istream>
#include "PlayerStrategy.h"

class ManualPlayerStrategy : PlayerStrategy {
    TurnResult play(
        std::list<CardPtr> &hand,
        const std::vector<CardPtr> &gamePile,
        const Command &input) final;
};

#endif
