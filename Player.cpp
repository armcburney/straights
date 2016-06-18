#include <iostream>
#include "Player.h"

using namespace std;

Player::Player () {
    cout << "Created player." << endl;
}

void Player::getScore() {
    cout << "Score is" << score.toInt() << endl;
}

void Player::playStrategy() {
    
}
