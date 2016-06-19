#include <istream>
#include <map>

#include "../Model/Straights.h"
#include "Context.h"

using namespace std;

TurnContext::TurnContext(const vector<CardPtr> &gamePile, const list<CardPtr> &hand)
    : gamePile(gamePile), hand(hand) {}

RoundContext::RoundContext(const vector<Player> &players)
    : players(players) {}


std::ostream &operator<<(std::ostream &out, const TurnContext& c) {
	string ranks[Card::RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K"};

    out << "Cards on the table:" << endl;

    // Print every card of every suit
    map<Card::Suit, string> suits = {{Card::CLUB, "Clubs"}, {Card::DIAMOND, "Diamonds"}, {Card::HEART, "Hearts"}, {Card::SPADE, "Spades"}};
    for (auto suit : suits) {
        out << suit.second << ":";
        for (CardPtr c : c.gamePile)
            if (c->getSuit() == suit.first)
                out << " " << ranks[c->getRank()];
    }
    out << endl;

    // Print the current player's hand
    out << "Your hand:";
    for (CardPtr c : c.hand)
        out << " " << *c;
    out << endl;

    // Print the player's legal plays
    vector<HandItr> legalPlays = Straights::getLegalPlays(c.hand, c.gamePile);
    out << "Legal plays:";
    for (HandItr c : legalPlays)
        out << " " << **c;
    out << endl;
}

std::ostream &operator<<(std::ostream &out, const RoundContext& c) {
    for (Player p : c.players)
        out << p << endl;
}
