#include "Straights.h"
#include "ManualPlayerStrategy.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

StrategyDecision ManualPlayerStrategy::play(
    list<CardPtr> &hand,
    const vector<CardPtr> &gamePile,
    const Command &input) {

    if (input.type == Command::NO_COMMAND) {
        // The manual strategy must get input from the user
        // to know what card to play / discard
        return StrategyDecision(StrategyDecision::REQUIRE_HUMAN_INPUT);
    } else {
        vector<HandItr> legalPlays = Straights::getLegalPlays(hand, gamePile);

        if (input.type == Command::PLAY) {
            // User wants to play a card
            auto legal_play_to_make = find_if(
                legalPlays.begin(),
                legalPlays.end(),
                [input] (HandItr it) {
                    return **it == input.card;
                }
            );
            if (legal_play_to_make == legalPlays.end()) {
                // Card user wants to play is not a legal move
                throw invalid_argument("This is not a legal play.");
            }
            HandItr card_to_play = *legal_play_to_make;
            return StrategyDecision(StrategyDecision::PLAY, card_to_play);
        } else if (input.type == Command::DISCARD) {
            // User wants to discard a card
            if (!legalPlays.empty()) {
                // Can't discard if there are legal plays
                throw invalid_argument("You have a legal play. You may not discard.");
            }
            // Find the card in the hand
            HandItr card_to_discard = find_if(
                hand.begin(),
                hand.end(),
                [input] (HandItr it) {
                    return **it == input.card;
                }
            );
            return StrategyDecision(StrategyDecision::DISCARD, card_to_discard);
        } else {
            throw logic_error("The strategy should only ever deal with commands of NO_COMMAND, PLAY, or DISCARD");
        }
    }
}
