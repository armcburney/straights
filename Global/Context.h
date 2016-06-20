#ifndef _CONTEXT_
#define _CONTEXT_

#include <istream>
#include <vector>
#include <list>
#include <set>

#include "../Model/Card.h"
#include "../Model/Player/Player.h"

struct TurnContext {
    const std::set<CardPtr, CardPtrComp> gamePile;
    const std::list<CardPtr> hand;

    TurnContext(const std::set<CardPtr, CardPtrComp>&, const std::list<CardPtr>&);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a TurnContext with gamePile and
      hand initialized.
    */
};

struct RoundContext {
    const std::vector<Player> players;

    RoundContext(const std::vector<Player>&);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a RoundContext with players
      initialized.
    */
};

std::ostream &operator<<(std::ostream &, const TurnContext&);
std::ostream &operator<<(std::ostream &, const RoundContext&);

#endif
