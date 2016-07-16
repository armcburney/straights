#ifndef _COMMAND_
#define _COMMAND_

#include "../Model/Card.h"
#include <istream>

struct Command{
    enum Type { PLAY, DISCARD, DECK, QUIT, RAGEQUIT, NO_COMMAND };

	Type type;
	Card card;

	Command(Type type = NO_COMMAND, Card card = Card(Card::SPADE, Card::ACE));
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a Command with:
        type = NO_COMMAND
        card = Ace of spades
    */
    Command(const Command&);
    /*
    PRECONDITIONS:
      - requires: a valid Command
    POSTCONDITIONS:
      - returns: a new Command with
        type = Command type
        card = Command card
    */
    Command& operator=(Command);
    /*
    PRECONDITIONS:
    POSTCONDITIONS:
    */
};

std::istream &operator>>(std::istream &, Command &);

#endif
