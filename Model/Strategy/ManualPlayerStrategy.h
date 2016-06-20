#ifndef _MANUAL_PLAYER_STRATEGY_
#define _MANUAL_PLAYER_STRATEGY_

#include <istream>
#include "PlayerStrategy.h"

class ManualPlayerStrategy : public PlayerStrategy {
    TurnResult play(
        std::list<CardPtr> &hand,
        const std::set<CardPtr, CardPtrComp> &gamePile,
        const Command &input) final;
    /*
    POSTCONDITIONS:
      - returns: an manual decision on the correct move to make
      given the game pile, player's hand, and player's input
    */
};

#endif
