#include <iostream>
#include "Player.h"
#include "Score.h"

using namespace std;

Score::Score() {
    score = 0;
}

int Score::toInt() {
    return score;
}
