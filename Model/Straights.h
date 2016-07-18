#ifndef _STRAIGHTS_
#define _STRAIGHTS_

#include <istream>
#include <set>
#include <vector>
#include <string>

#include "Card.h"
#include "Deck.h"
#include "Player/Player.h"
#include "../Global/Command.h"
#include "../Global/TurnResult.h"
#include "../Global/Context.h"
#include "../Global/Subject.h"

typedef std::vector<Player>::iterator PlayerItr;

class Straights : public Subject<RoundContext> {
    friend std::ostream &operator<<(std::ostream &out, const Straights &s);

public:
    Straights(int seed);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to Straights with seed = 0, empty gamePile, full
      deck, and no players
    */
    void addHumanPlayer(int);
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: players with new player having id passed in
    */
    void addComputerPlayer(int);
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: players with new player having id passed in
    */
    void automateCurrentPlayer();
    /*
    POSTCONDITIONS:
      - modifies: currentPlayer
      - ensures: currentPlayer has AutomatedPlayerStrategy
    */
    PlayerItr returnCurrentPlayer() const;
    /*
    POSTCONDITIONS:
      - return: currentPlayer
    */
    std::string returnWinner(const Straights &s) const;
    /*
    POSTCONDITIONS:
      - return: game winner
    */
    void clearRound();
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: the game pile is emptied and players hands and discard piles are emptied
    */
    void deal();
    /*
    POSTCONDITIONS:
      - modifies: players, deck
      - ensures: shuffles the deck and evenly distributes them amongst players
    */

    TurnResult next(const Command &input = Command());
    /*
    PRECONDITION:
      - requires: players
    POSTCONDITIONS:
      - modifies: this
      - ensures: currentPlayer plays their strategy, the game and round are checked
      for completion
    */
    TurnContext getTurnContext() const;
    /*
    POSTCONDITIONS:
      - returns: an object describing the game pile and player's hand
    */
    RoundContext getRoundContext() const;
    /*
    POSTCONDITIONS:
      - returns: an object describing the current round
    */
    Deck getDeck() const;
    /*
    POSTCONDITIONS:
      - returns: the deck
    */

    static std::vector<CardPtr> getLegalPlays(
        std::list<CardPtr> hand,
        const std::set<CardPtr, CardPtrComp> &gamePile);
    /*
    PRECONDITIONS:
      - requires: the hand is not empty
    POSTCONDITIONS:
      - returns: all possible legal moves given the hand and game pile
    */

protected:
    // Notify the view of changes to the model
    void notify();

private:
    int seed_;
    Deck deck;
    std::set<CardPtr, CardPtrComp> gamePile;
    std::vector<Player> players;
    PlayerItr currentPlayer;

    static const Score endingScoreThreshold;
};

// Output
std::ostream &operator<<(std::ostream &out, const Straights &s);

#endif
