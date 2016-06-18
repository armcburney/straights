#include <iostream>
#include "Player.h"

using namespace std;

Player::Player (int id) : score() {
    // cout << "Created player " <<  id << endl;
}

void Player::getScore() {
    cout << "Score is" << score.toInt() << endl;
}

void Player::playStrategy() {

}
