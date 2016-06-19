#include "Command.h"
#include <cassert>
#include <sstream>

using namespace std;

istream &operator>>(istream &in, Command &c){
    in.ignore();

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

	assert(!in.fail() && !ss.fail() && c.type != Command::NO_COMMAND);

	return in;
}
