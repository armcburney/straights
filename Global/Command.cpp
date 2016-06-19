#include "Command.h"
#include <cassert>
#include <sstream>

using namespace std;

Command::Command() : type(NO_COMMAND), card(Card::SPADE, Card::ACE) {}

Command::Command(const Command&) = default;

Command& Command::operator=(Command c) {
    swap(type, c.type);
    swap(card, c.card);
    return *this;
}

istream &operator>>(istream &in, Command &c){
	c.type = Command::NO_COMMAND;

	string str;
	getline(in, str);
	stringstream ss(str);

	string cmd;
	ss >> cmd;

	if (cmd == "play") {
		c.type = Command::PLAY;
		ss >> c.card;
	} else if (cmd == "discard") {
		c.type = Command::DISCARD;
		ss >> c.card;
	} else if (cmd == "deck") {
		c.type = Command::DECK;
	} else if (cmd == "quit") {
		c.type = Command::QUIT;
	} else if (cmd == "ragequit") {
		c.type = Command::RAGEQUIT;
	}

	return in;
}
