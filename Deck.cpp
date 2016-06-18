#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

Deck::Deck () {
    for (int i = CLUB; i < SUIT_COUNT; i++) {
        for (int j = ACE; j < RANK_COUNT; j++) {
            Card* c = new Card(static_cast<Suit>(i), static_cast<Rank>(j));
            cards.push_back(c);
        }
    }
}
