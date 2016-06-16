#ifndef _PLAYER_
#define _PLAYER_

#include <istream>
#include <vector>

#include "Card.h"
#include "Score.h"
#include "PlayerStrategy.h"

class Player {
public:
    Player();                           // Constructor
    ~Player();                          // Destructor
    void getScore();                    // Prints players score
    void playStrategy();                // Plays the current turn
private:
    int id;                             // Player id -> integer 1-4, (ie. Player 1)
    Score score;                        // Current player score
    PlayerStrategy * strategy;          // Player strategy (human or computer -> inherited in child classes)
    std::vector<Card *> hand;           // Player hand
    std::vector<Card *> discardPile;    // Player discard pile
};

#endif
