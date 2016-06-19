#include "Controller.h"
#include "../Global/Context.h"
#include "../Model/Deck.h"

using namespace std;

Controller::Controller(Straights &model, View &view)
    : model(model), view(view) {}

void Controller::startGame() {
    vector<char> playerTypes = view.getPlayers();

    for (int i = 0; i < 4; i++) {
        if (playerTypes[i] == 'c')
            model.addComputerPlayer(i+1);
        else
            model.addHumanPlayer(i+1);
    }
    cout << "test?" << endl;

    model.deal();

    view.printObject<Straights>(model);

    while (true) {
        TurnResult turnResult = model.next();

        if (turnResult.getType() == TurnResult::REQUIRE_HUMAN_INPUT) {
            view.printObject<TurnContext>(model.getTurnContext());

            bool validInputProvided = false;
            while (!validInputProvided) {
                cout << "Ready for input" << endl;
                Command input = view.getCommand();
                cout << "After input" << endl;
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
                        break;
                    }
                    default: {
                        try {
                            turnResult = model.next(input);
                            validInputProvided = true;
                        } catch (const invalid_argument &e) {
                            view.printObject<string>(e.what());
                        }
                        break;
                    }
                }
            }
        }

        view.printObject<TurnResult>(turnResult);

        if (turnResult.getStatus() == TurnResult::ROUND_COMPLETE ||
            turnResult.getStatus() == TurnResult::GAME_COMPLETE) {

            view.printObject<RoundContext>(model.getRoundContext());
            view.printObject<Straights>(model);
        }

        if (turnResult.getStatus() == TurnResult::GAME_COMPLETE)
            return;
    }
}
