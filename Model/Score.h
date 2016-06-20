#ifndef _SCORE_
#define _SCORE_

#include <istream>

class Score {
public:
    friend std::ostream& operator<< (std::ostream&, const Score&);
    Score& operator= ( const Score& );

    Score(int);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a Score with score passed in
    */
    int toInt() const;
    /*
    POSTCONDITIONS:
      - returns: the object's score as an int
    */
private:
    int score;
};

// Operators

Score operator+(const Score &a, const Score &b);
Score operator-(const Score &a, const Score &b);

bool operator== (const Score &a, const Score &b);
bool operator!= (const Score &a, const Score &b);
bool operator< (const Score &a, const Score &b);
bool operator<= (const Score &a, const Score &b);
bool operator> (const Score &a, const Score &b);
bool operator>= (const Score &a, const Score &b);

#endif
