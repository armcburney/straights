#ifndef _PLAYER_
#define _PLAYER_

#include <istream>
#include <memory>
#include <vector>
#include <list>

#include "../Card.h"
#include "../Score.h"
#include "../Strategy/PlayerStrategy.h"
#include "../../Global/TurnResult.h"

class Player {
public:
    Player(int, std::shared_ptr<PlayerStrategy> strategy);
    int getID() const;                           // Returns id
    Score getScore() const;                      // Prints players score
    TurnResult playStrategy(std::vector<CardPtr>&, const Command&);
    bool allCardsPlayed() const;
    void clearRound();
    void setHand(std::list<CardPtr>);
private:
    int id;                               // Player id -> integer 1-4, (ie. Player 1)
    Score score;                          // Current player score
    std::shared_ptr<PlayerStrategy> strategy;
    std::list<CardPtr> hand;              // Player hand
    std::vector<CardPtr> discardPile;     // Player discard pile
};

// Convenient shorthand for card hand iterator
typedef std::list<CardPtr>::iterator HandItr;

#endif
