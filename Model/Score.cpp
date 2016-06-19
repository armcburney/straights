#include <iostream>

#include "Player/Player.h"
#include "Score.h"

using namespace std;

Score::Score(int n) {
    score = n;
}

int Score::toInt() const {
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


//===================================================================
// Comparison operators
//===================================================================

Score operator+(const Score &a, const Score &b) {
    return Score(a.toInt() + b.toInt());
}

Score operator-(const Score &a, const Score &b) {
    return Score(a.toInt() - b.toInt());
}

bool operator== (const BCode &a, const BCode &b) {
	return a.toString() == b.toString();
}

bool operator!= (const BCode &a, const BCode &b) {
	return !(a==b);
}

bool operator< (const BCode &a, const BCode &b) {
	return a.toString() < b.toString();
}

bool operator<= (const BCode &a, const BCode &b) {
	return (a<b) || (a==b);
}

bool operator> (const BCode &a, const BCode &b) {
	return !(a<=b);
}

bool operator>= (const BCode &a, const BCode &b) {
	return !(a<b);
}
