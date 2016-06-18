#include <string>
#include <iostream>

#include "Player.h"
#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer(int id) : Player(id) {
    cout << "computer player" << endl;
}
