#ifndef _DECK_
#define _DECK_

#include <string>
#include <vector>

#include "Card.h"

enum {CARD_COUNT = 52};

class Deck {
public:
    Deck();
    std::vector<CardPtr> cards() const;     // cards accessor
    void shuffle(int);
private:
    std::vector<CardPtr> cards_;
};

std::ostream & operator<<(std::ostream &out, const Deck &d);

#endif
