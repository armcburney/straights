#ifndef _PLAYER_
#define _PLAYER_

#include <istream>
#include <memory>
#include <vector>
#include <list>
#include <set>

#include "../Card.h"
#include "../Score.h"
#include "../Strategy/PlayerStrategy.h"
#include "../../Global/TurnResult.h"

class Player {
    friend std::ostream &operator<<(std::ostream &out, const Player &p);

public:
    enum Type { COMPUTER, HUMAN };

    Player(int, std::shared_ptr<PlayerStrategy> strategy);
    virtual ~Player() = default;
    /*
    POSTCONDITIONS:
      - ensures: initializes this to Player with id, score = 0, roundScore = 0, and
      strategy initialized
    */
    int getID() const;
    /*
    POSTCONDITIONS:
      - returns: player's id
    */
    Score getScore() const;
    /*
    POSTCONDITIONS:
      - returns: player's score
    */
    TurnResult playStrategy(std::set<CardPtr, CardPtrComp>&, const Command&);
    /*
    PRECONDITION:
      - requires: player has a strategy
    POSTCONDITIONS:
      - ensures: that the player's strategy is played
      - returns: the result of the strategy decision
    */
    bool allCardsPlayed() const;
    /*
    POSTCONDITIONS:
      - returns: true if hand is empty
    */
    void clearRound();
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: hand, discardPile are cleared, and the score is updated
    */
    void setHand(std::list<CardPtr>);
    /*
    POSTCONDITIONS:
      - modifies: this
      - ensures: hand is set to the value passed in
    */
    std::list<CardPtr> getHand() const;
    /*
    POSTCONDITIONS:
      - returns: player's hand
    */
    void setStrategy(std::shared_ptr<PlayerStrategy>);
    /*
    PRECONDITION:
      - requires: a valid player strategy
    POSTCONDITIONS:
      - ensures: the player strategy is updated to the value passed in
    */
    bool hasCard(Card) const;
    /*
    PRECONDITION:
      - requires: a valid card
    POSTCONDITIONS:
      - returns: true if the player has the card
    */
    int getNumCardsDiscarded() const;
    virtual Type getType() const;

private:
    int id;                               // Player id -> integer 1-4, (ie. Player 1)
    Score score;                          // Current player score
    Score roundScore;
    std::shared_ptr<PlayerStrategy> strategy;
    std::list<CardPtr> hand;              // Player hand
    std::vector<CardPtr> discardPile;     // Player discard pile
};

// Output
std::ostream &operator<<(std::ostream &out, const Player &p);

#endif
