#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include "Player.h"
#include <istream>

class ComputerPlayer : public Player {
public:
    ComputerPlayer(int);
    /*
    POSTCONDITIONS:
      - ensures: created a derived ComputerPlayer of the parent Player with:
        id = id
        score = 0
        roundScore = 0
        lastRoundScore = 0
        strategy = AutomatedPlayerStrategy
    */
};

#endif
