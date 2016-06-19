#include <string>
#include <iostream>

#include "HumanPlayer.h"
#include "../Strategy/ManualPlayerStrategy.h"

using namespace std;

HumanPlayer::HumanPlayer(int id)
    : Player(id, shared_ptr<PlayerStrategy>(new ManualPlayerStrategy)) {}
