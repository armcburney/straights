#ifndef _SCORE_
#define _SCORE_

#include <istream>

class Score {
public:
    Score(int);
    int toInt();
private:
    int score;
    friend std::ostream& operator<< (std::ostream&, const Score&);  // insertion operator (insert graph into output stream)
    Score& operator= ( const Score& );                              // assignment operator for graph objects
    bool operator== ( const Score& ) const;                         // equality operator for graph objects
};

bool operator== (const BCode &a, const BCode &b);
bool operator!= (const BCode &a, const BCode &b);
bool operator< (const BCode &a, const BCode &b);
bool operator<= (const BCode &a, const BCode &b);
bool operator> (const BCode &a, const BCode &b);
bool operator>= (const BCode &a, const BCode &b);

#endif
