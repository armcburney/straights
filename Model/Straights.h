#ifndef _STRAIGHTS_
#define _STRAIGHTS_

#include <istream>
#include <list>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player/Player.h"
#include "../Global/Command.h"
#include "../Global/TurnResult.h"
#include "../Global/Context.h"

typedef std::vector<Player>::iterator PlayerItr;

class Straights {
    friend std::ostream &operator<<(std::ostream &out, const Straights &s);

public:
    Straights();
    void addHumanPlayer(int);
    void addComputerPlayer(int);
    void deal();
    void setShuffleSeed(int);
    TurnResult next(const Command &input = Command());
    TurnContext getTurnContext() const;
    RoundContext getRoundContext() const;
    Deck getDeck() const;
    void automateCurrentPlayer();

    static std::vector<HandItr> getLegalPlays(
        std::list<CardPtr> hand,
        const std::vector<CardPtr> &gamePile);
private:
    void clearRound();

    int seed_;
    Deck deck;
    std::vector<CardPtr> gamePile;
    std::vector<Player> players;
    PlayerItr currentPlayer;

    static const Score endingScoreThreshold;
};

// Output
std::ostream &operator<<(std::ostream &out, const Straights &s);

#endif
