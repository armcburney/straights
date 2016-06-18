#ifndef _STRAIGHTS_
#define _STRAIGHTS_

#include <istream>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Straights {
public:
    Straights();
    void addHumanPlayer();
    void addComputerPlayer();
    void deal();
    void next(bool);
private:
    Deck deck;
    std::vector<Card*> gamePile;
    std::vector<Player> players;
    int currentPlayer; // id
    int currentRound;
};

#endif
