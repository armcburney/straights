#ifndef _AUTO_PLAYER_STRATEGY_
#define _AUTO_PLAYER_STRATEGY_

#include <istream>
#include "PlayerStrategy.h"

class AutomatedPlayerStrategy : public PlayerStrategy {
    TurnResult play(
        std::list<CardPtr> &hand,
        const std::set<CardPtr, CardPtrComp> &gamePile,
        const Command &input) final;
    /*
    POSTCONDITIONS:
      - returns: an automated decision on the correct move to make
      given the game pile and player's hand
    */
};

#endif
