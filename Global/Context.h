#ifndef _CONTEXT_
#define _CONTEXT_

#include <istream>
#include <vector>
#include <list>
#include <set>

#include "../Model/Card.h"
#include "../Model/Player/Player.h"

// Used to describe the options available to the current player
struct TurnContext {
    const std::list<CardPtr> hand;
    const std::set<CardPtr, CardPtrComp> gamePile;
    const std::vector<CardPtr> legalPlays;

    TurnContext(
        const std::list<CardPtr>                & hand,
        const std::set<CardPtr, CardPtrComp>    & gamePile
    );
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a TurnContext with gamePile and
      hand initialized.
    */
};

// Used to describe the state of the round & every player
struct RoundContext {
    const std::vector<Player> players;
    const int currentPlayerId;
    const std::set<CardPtr, CardPtrComp> gamePile;
    const std::vector<std::vector<TurnResult>> playerRoundMoves;
    const std::vector<Score> playerScores;
    const std::vector<Player::Type> playerTypes;

    RoundContext(
        const std::vector<Player>                       & players,
        const int                                       & currentPlayerId,
        const std::set<CardPtr, CardPtrComp>            & gamePile,
        const std::vector<std::vector<TurnResult>> & numDiscardsPerPlayer,
        const std::vector<Score>                        & playerScores,
        const std::vector<Player::Type>                 & playerTypes
    );
};

std::ostream &operator<<(std::ostream &, const TurnContext&);
std::ostream &operator<<(std::ostream &, const RoundContext&);

#endif
