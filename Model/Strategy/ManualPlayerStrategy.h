#ifndef _MANUAL_PLAYER_STRATEGY_
#define _MANUAL_PLAYER_STRATEGY_

#include <istream>
#include "PlayerStrategy.h"

class ManualPlayerStrategy : public PlayerStrategy {
    TurnResult play(
        std::list<CardPtr> &hand,
        const std::set<CardPtr, CardPtrComp> &gamePile,
        const Command &input) final;
};

#endif
