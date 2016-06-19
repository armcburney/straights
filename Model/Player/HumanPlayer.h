#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include "Player.h"
#include <istream>

class HumanPlayer : public Player {
public:
    HumanPlayer(int);
    void automate(); // changes the player strategy of the Player
};

#endif
