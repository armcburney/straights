#include "../Straights.h"
#include "AutomatedPlayerStrategy.h"

using namespace std;

TurnResult AutomatedPlayerStrategy::play(
    list<CardPtr> &hand,
    const set<CardPtr, CardPtrComp> &gamePile,
    const Command&) {

    vector<CardPtr> legalPlays = Straights::getLegalPlays(hand, gamePile);

    if (!legalPlays.empty()) {
        // There are legal moves, so make the first one
        return TurnResult(TurnResult::TURN_COMPLETE, TurnResult::PLAY, legalPlays[0]);
    } else {
        // No moves, discard the first card
        return TurnResult(TurnResult::TURN_COMPLETE, TurnResult::DISCARD, hand.front());
    }
}
