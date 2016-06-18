#ifndef _STRATEGYDECISION_
#define _STRATEGYDECISION_

#include "Player.h"
#include "Card.h"

#include <istream>

typedef std::list<CardPtr>::iterator HandItr;

struct StrategyDecision {
    enum Type {
        PLAY = 'p',
        DISCARD = 'd',
        REQUIRE_HUMAN_INPUT = 'i',
    };

    Type type;
    HandItr card;

    StrategyDecision(Type type, HandItr card) : type(type), card(card) {};
    StrategyDecision(Type type) : type(type) {};
};

#endif
