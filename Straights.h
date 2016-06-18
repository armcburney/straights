#ifndef _STRAIGHTS_
#define _STRAIGHTS_

#include <istream>
#include <list>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Straights {
public:
    Straights();
    void addHumanPlayer(int);
    void addComputerPlayer(int);
    void deal();
    void next(bool);

    static std::vector<HandItr> getLegalPlays(
        const std::list<CardPtr> &hand,
        const std::vector<CardPtr> &gamePile);
private:
    Deck deck;
    std::vector<CardPtr> gamePile;
    std::vector<Player> players;
    int currentPlayer; // id
    int currentRound;
};

#endif
