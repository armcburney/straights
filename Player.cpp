#include <iostream>
#include "Player.h"

using namespace std;

Player::Player (int id) : id(id), score() {}

void Player::getScore () {
    cout << "Score is" << score.toInt() << endl;
}

void Player::playStrategy () {}

int Player::getID () {
    return id;
}
