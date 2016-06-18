#ifndef _PLAYER_
#define _PLAYER_

#include <istream>
#include <vector>
#include <list>

#include "Card.h"
#include "Score.h"
#include "PlayerStrategy.h"

class Player {
public:
    Player(int);                        // Constructor
    int getID();                       // Returns id
    void getScore();                    // Prints players score
    void playStrategy();                // Plays the current turn
private:
    int id;                             // Player id -> integer 1-4, (ie. Player 1)
    Score score;                        // Current player score
    PlayerStrategy * strategy;          // Player strategy (human or computer -> inherited in child classes)
    std::list<CardPtr> hand;            // Player hand
    std::vector<CardPtr> discardPile;   // Player discard pile
};

// Convenient shorthand for card hand iterator
typedef std::list<CardPtr>::iterator HandItr;

#endif
