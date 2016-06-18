#ifndef _DECK_
#define _DECK_

#include <string>
#include <vector>

#include "Card.h"

class Deck {
public:
    Deck();
private:
    std::vector<std::string> Cards;
};

#endif
