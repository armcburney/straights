// controller.cpp

#include "Controller.h"

using namespace std;

Controller::Controller(Straights &model, View &view)
    : model(model), view(view) {}

void Controller::startGame() {
    view.printObject(model);

    vector<char> players = view.getPlayers();

    for (auto i : players) {
        if (i == 'c')
            model.addComputerPlayer(0);
        else
            model.addHumanPlayer(0);
    }

    while (true) {
        TurnResult turnResult = model.next();

        if (turnResult.getType() == TurnResult::REQUIRE_HUMAN_INPUT) {
            view.printObject(model.getTurnContext);

            bool validInputProvided = false;
            while (!validInputProvided) {
                Command input = view.getCommand();
                switch (input.type) {
                    case Command::DECK: {
                        view.printObject(model.getDeck());
                        break;
                    }
                    case Command::QUIT: {
                        return;
                    }
                    case Command::RAGEQUIT: {
                        model.automateCurrentPlayer();
                        break;
                    }
                    default: {
                        try {
                            turnResult = model.next(input);
                            validInputProvided = true;
                        } catch (const invalid_argument &e) {
                            view.printObject(e.what());
                        }
                        break;
                    }
                }
            }
        }

        view.printObject(turnResult);

        if (turnResult.getStatus() == TurnResult::ROUND_COMPLETE ||
            turnResult.getStatus() == TurnResult::GAME_COMPLETE) {

            view.printObject(model.getRoundContext());
            view.printObject(model);
        }

        if (turnResult.getStatus() == TurnResult::GAME_COMPLETE)
            return;
    }
}
