#include <iostream>

#include "Player/Player.h"
#include "Score.h"

using namespace std;

Score::Score(int n) {
    score = n;
}

Score& Score::operator=(const Score&) = default;

int Score::toInt() const {
    return score;
}

ostream & operator<<(ostream &sout, const Score & s) {
    sout << s.score;
    return sout;
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

bool operator== (const Score &a, const Score &b) {
	return a.toInt() == b.toInt();
}

bool operator!= (const Score &a, const Score &b) {
	return !(a==b);
}

bool operator< (const Score &a, const Score &b) {
	return a.toInt() < b.toInt();
}

bool operator<= (const Score &a, const Score &b) {
	return (a<b) || (a==b);
}

bool operator> (const Score &a, const Score &b) {
	return !(a<=b);
}

bool operator>= (const Score &a, const Score &b) {
	return !(a<b);
}
