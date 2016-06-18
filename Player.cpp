#include <iostream>
#include "Player.h"

using namespace std;

Player::Player (int id) : score() {}

void Player::getScore () {
    cout << "Score is" << score.toInt() << endl;
}

void Player::playStrategy () {

}
