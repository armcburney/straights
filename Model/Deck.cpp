#include <iostream>
#include <random>

#include "Card.h"
#include "Deck.h"

using namespace std;

Deck::Deck () {
    for (int i = CLUB; i < SUIT_COUNT; i++) {
        for (int j = ACE; j < RANK_COUNT; j++) {
            Card* c = new Card(static_cast<Suit>(i), static_cast<Rank>(j));
            cards_.push_back(c);
        }
    }
}

vector<Card *> Deck::cards() {
    return cards_;
}

void Deck::shuffle() {
    int seed = 0;
    static mt19937 rng(seed);

    int n = CARD_COUNT;

    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        Card *c = cards_[n];
        cards_[n] = cards_[k];
        cards_[k] = c;
    }
}
