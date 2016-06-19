// controller.cpp

#include "Controller.h"

using namespace std;

Controller::Controller(Straights &model, View &view)
    : model(model), view(view) {}

void Controller::startGame() {
    view.printObject(model);

    while (true) {
        TurnResult turnResult = model.next();
        if (turnResult.getType() == TurnResult::REQUIRE_HUMAN_INPUT) {
            view.printObject(model.getTurnContext);
            // Insert for loop with try-catch n such
            turnResult = model.next(view.getCommand());
        }

        view.printObject(turnResult);

        if (turnResult.getStatus() == TurnResult::GAME_COMPLETE ||
            turnResult.getStatus() == TurnResult::ROUND_COMPLETE)
            view.printObject(model);

        if (turnResult.getStatus() == TurnResult::GAME_COMPLETE)
            break;
    }
}
