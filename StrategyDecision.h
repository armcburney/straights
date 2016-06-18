#ifndef _STRATEGYDECISION_
#define _STRATEGYDECISION_

#include <istream>
#include <memory>
#include "Card.h"

class StrategyDecision {
public:
    enum decisionTypes {
        PLAY = 'p',
        DISCARD = 'd',
        REQUIRE_HUMAN_INPUT = 'i',
    };

    char getDecisionType() const;
    std::shared_ptr<Card> getCard() const;

    StrategyDecision(char, std::shared_ptr<Card>);

private:
    const char decisionType;
    const std::shared_ptr<Card> card;
};

#endif
