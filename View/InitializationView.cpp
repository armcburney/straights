#include <iostream>
#include <string>
#include <vector>

#include "InitializationView.h"

using namespace std;

InitializationView::InitializationView(weak_ptr<Controller> controller)
    : controller(controller) {
    // TODO Load glade template
}

void InitializationView::startGameButtonClicked() {
    vector<Player::Type> playerTypes;
    int randomSeed = 0;
    // TODO Get player types and random seed
    if (auto c = controller.lock())
        c->startGame(playerTypes, randomSeed);
}
