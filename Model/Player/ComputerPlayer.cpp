#include <string>
#include <iostream>

#include "ComputerPlayer.h"
#include "AutomatedPlayerStrategy.h"

using namespace std;

ComputerPlayer::ComputerPlayer(int id)
    : Player(id, shared_ptr<PlayerStrategy>(new AutomatedPlayerStrategy)) {}
