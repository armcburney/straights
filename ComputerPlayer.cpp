#include <string>
#include <iostream>

#include "Player.h"
#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer() : Player(0) { // review this lol
    cout << "computer player" << endl;
}
