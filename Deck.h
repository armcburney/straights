#ifndef _DECK_
#define _DECK_

#include <string>
#include <vector>

#include "Card.h"

enum {CARD_COUNT = 52};

class Deck {
public:
    Deck();
    std::vector<Card* > cards();    // cards accessor
    void shuffle();  // cards accessor
private:
    std::vector<Card *> cards_;
};

#endif
