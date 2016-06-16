#include <iostream>
#include "Player.h"

using namespace std;

Player::Player () {
    cout << "Created player." << endl;
}
Player::~Player () {
    cout << "Player dies :(" << endl;
}

void Player::getScore() {
    cout << "Score is" << score.toInt() << endl;
}
