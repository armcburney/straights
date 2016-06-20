#include "Controller.h"
#include "../Global/Context.h"
#include "../Model/Deck.h"

using namespace std;

Controller::Controller(Straights &model, View &view)
    : model(model), view(view) {}

void Controller::startGame() {
    vector<char> playerTypes = view.getPlayerTypes();

    // Given the 4 player types, create the players in the game
    for (int i = 0; i < 4; i++) {
        if (playerTypes[i] == 'c')
            model.addComputerPlayer(i+1);
        else
            model.addHumanPlayer(i+1);
    }

    model.deal();

    // Print a summary of the game before starting
    view.printObject<Straights>(model);

    while (true) {
        // Start the next round
        TurnResult turnResult = model.next();

        if (turnResult.getType() == TurnResult::REQUIRE_HUMAN_INPUT) {
            // We require more input from the user to complete the round

            // Print the context for the user to decide
            view.printObject<TurnContext>(model.getTurnContext());

            bool validInputProvided = false;
            while (!validInputProvided) {
                // Read commands from the player

                Command input = view.getCommand();
                switch (input.type) {
                    case Command::DECK: {
                        view.printObject<Deck>(model.getDeck());
                        break;
                    }
                    case Command::QUIT: {
                        return;
                    }
                    case Command::RAGEQUIT: {
                        model.automateCurrentPlayer();
                        view.printRagequit(model.returnCurrentPlayer()->getID());
                        input = Command();
                    }
                    default: {
                        try {
                            turnResult = model.next(input);
                            validInputProvided = true;
                        } catch (const invalid_argument &e) {
                            view.printObject<string>(e.what());
                            view.printNewLine();
                        }
                        break;
                    }
                }
            }
        }

        // Print a summary of the move made
        view.printObject<TurnResult>(turnResult);

        if (turnResult.getStatus() == TurnResult::ROUND_COMPLETE ||
            turnResult.getStatus() == TurnResult::GAME_COMPLETE) {

            view.printObject<RoundContext>(model.getRoundContext());

            // Prepare the next round
            model.clearRound();
            model.deal();

            // Print a summarry of the game
            view.printObject<Straights>(model);
        }

        if (turnResult.getStatus() == TurnResult::GAME_COMPLETE)
            // The game is over
            return;
    }
}
