#ifndef _STRAIGHTS_
#define _STRAIGHTS_

#include <istream>
#include <list>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

typedef std::vector<Player>::iterator PlayerItr;

class Straights {
public:
    Straights();
    void addHumanPlayer(int);
    void addComputerPlayer(int);
    void deal();
    TurnResult next(const Command &input = Command());
    TurnContext getTurnContext() const;

    static std::vector<HandItr> getLegalPlays(
        std::list<CardPtr> hand,
        const std::vector<CardPtr> &gamePile);
private:
    void clearRound();

    Deck deck;
    std::vector<CardPtr> gamePile;
    std::vector<Player> players;
    PlayerItr currentPlayer;
    int currentRound;

    static const Score endingScore;
};

#endif
