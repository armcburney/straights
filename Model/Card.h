#ifndef _CARD_
#define _CARD_

#include <ostream>
#include <istream>
#include <memory>

class Card {
	friend std::istream &operator>>(std::istream &, Card &);

public:
    enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
    enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

	Card(Suit, Rank);
	/*
	POSTCONDITIONS:
	  - ensures: created a Card with
		suit_ = Suit
		rank_ = Rank
	*/
	Suit getSuit() const;
	Rank getRank() const;

private:
	Suit suit_;
	Rank rank_;
};

bool operator==(const Card &, const Card &);

//output/input Card in the format <rank><suit>
std::ostream &operator<<(std::ostream &, const Card &);
std::istream &operator>>(std::istream &, Card &);

// Convenient shorthand for smart pointer
typedef std::shared_ptr<Card> CardPtr;

// Key for sorting CardPtrs
struct CardPtrComp {
    bool operator()(const CardPtr, const CardPtr) const;
};

#endif
