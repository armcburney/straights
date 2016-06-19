#ifndef _DECK_
#define _DECK_

#include <string>
#include <vector>

#include "Card.h"

enum {CARD_COUNT = 52};

class Deck {
    friend std::ostream &operator<<(std::ostream &out, const Deck &d);

public:
    Deck();
    std::vector<CardPtr> cards() const;     // cards accessor
    void shuffle(int);                         // cards accessor
private:
    std::vector<CardPtr> cards_;
};

#endif
