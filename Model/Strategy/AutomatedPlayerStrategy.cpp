#include "../Straights.h"
#include "AutomatedPlayerStrategy.h"

using namespace std;

TurnResult AutomatedPlayerStrategy::play(
    list<CardPtr> &hand,
    const set<CardPtr, CardPtrComp> &gamePile,
    const Command&) {

    set<CardPtr, CardPtrComp> legalPlays = Straights::getLegalPlays(hand, gamePile);

    if (!legalPlays.empty()) {
        // There are legal moves, so make the first one
        return TurnResult(TurnResult::TURN_COMPLETE, TurnResult::PLAY, *legalPlays.begin());
    } else {
        // No moves, discard the first card
        return TurnResult(TurnResult::TURN_COMPLETE, TurnResult::DISCARD, hand.front());
    }
}
