#ifndef _PLAYER_
#define _PLAYER_

#include <istream>
#include <memory>
#include <vector>
#include <list>
#include <set>

#include "../Card.h"
#include "../Score.h"
#include "../Strategy/PlayerStrategy.h"
#include "../../Global/TurnResult.h"

class Player {
    friend std::ostream &operator<<(std::ostream &out, const Player &p);

public:
    Player(int, std::shared_ptr<PlayerStrategy> strategy);
    int getID() const;                           // Returns id
    Score getScore() const;                      // Prints players score
    TurnResult playStrategy(std::set<CardPtr, CardPtrComp>&, const Command&);
    bool allCardsPlayed() const;
    void clearRound();
    void setHand(std::list<CardPtr>);
    std::list<CardPtr> getHand() const;
    void setStrategy(std::shared_ptr<PlayerStrategy>);
    bool hasCard(Card) const;
private:
    int id;                               // Player id -> integer 1-4, (ie. Player 1)
    Score score;                          // Current player score
    Score roundScore;
    std::shared_ptr<PlayerStrategy> strategy;
    std::list<CardPtr> hand;              // Player hand
    std::vector<CardPtr> discardPile;     // Player discard pile
};

// Output
std::ostream &operator<<(std::ostream &out, const Player &p);

#endif
