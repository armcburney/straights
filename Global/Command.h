#ifndef _COMMAND_
#define _COMMAND_

#include "../Model/Card.h"
#include <istream>

struct Command{
    enum Type { PLAY, DISCARD, DECK, QUIT, RAGEQUIT, NO_COMMAND };

	Type type;
	Card card;

	Command() : type(NO_COMMAND), card(SPADE, ACE) {}
};

std::istream &operator>>(std::istream &, Command &);

#endif
