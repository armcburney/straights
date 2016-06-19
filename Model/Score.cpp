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

ostream & operator<<(ostream &sout, const Score & s) {
    sout << s.score << endl;
    return sout;
}

bool Score::operator==(const Score& s) const {
    if (score == s.score)
        return true;
    else
        return false;
}
