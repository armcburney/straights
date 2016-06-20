#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include <istream>

class HumanPlayer : public Player {
public:
    HumanPlayer(int);
    /*
    POSTCONDITIONS:
      - ensures: created a derived ComputerPlayer of the parent Player with:
        id = id
        score = 0
        roundScore = 0
        lastRoundScore = 0
        strategy = ManualPlayerStrategy
    */
};

#endif
