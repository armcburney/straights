#include <iostream>

#include "Player/Player.h"
#include "Score.h"

using namespace std;

Score::Score(int n) {
    score = n;
}

int Score::toInt() {
    return score;
}
