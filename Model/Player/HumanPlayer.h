#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include <istream>

class HumanPlayer : public Player {
public:
    HumanPlayer(int);
    /*
    POSTCONDITIONS:
      - ensures: creates a derived HumanPlayer of the parent Player with:
        id = id
        score = 0
        roundScore = 0
        lastRoundScore = 0
        strategy = ManualPlayerStrategy
    */
    virtual Type getType() const final;
};

#endif
