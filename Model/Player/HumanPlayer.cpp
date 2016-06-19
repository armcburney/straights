#include <string>
#include <iostream>

#include "Player.h"
#include "HumanPlayer.h"
#include "../Strategy/ManualPlayerStrategy.h"

using namespace std;

HumanPlayer::HumanPlayer(int id)
    : Player(id, shared_ptr<PlayerStrategy>(new ManualPlayerStrategy)) {}

void HumanPlayer::automate() {
    strategy = shared_ptr<PlayerStrategy>(new AutomatedPlayerStrategy);
}
