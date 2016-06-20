#ifndef _DECK_
#define _DECK_

#include <string>
#include <vector>

#include "Card.h"

enum {CARD_COUNT = 52};

class Deck {
public:
    Deck();
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a Deck object with 52
      cards in order
    */
    std::vector<CardPtr> cards() const;
    /*
    POSTCONDITIONS:
      - returns: the deck's cards_
    */
    void shuffle(int);
    /*
    PRECONDITIONS:
      - requires: 52 cards in the deck
    POSTCONDITIONS:
      - modifies: the deck's cards_
      - ensures: order is randomized
    */
private:
    std::vector<CardPtr> cards_;
};

std::ostream & operator<<(std::ostream &out, const Deck &d);

#endif
