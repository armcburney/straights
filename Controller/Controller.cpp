#include "Controller.h"
#include "../Model/Deck.h"

#include "../Global/Subject.cpp"

using namespace std;

Controller::Controller(unique_ptr<TextView> textView) : textView(move(textView)) {}

void Controller::initialize() {
    // Show the initialization window
    initializationView = unique_ptr<InitializationView>(
        new InitializationView(shared_from_this())
    );
    initializationView->show();
}

void Controller::startGame(vector<Player::Type> playerTypes, int randomSeed) {
    // Create the game model & view
    model = unique_ptr<Straights>(new Straights(randomSeed));
    gameView = shared_ptr<GameView>(
        new GameView(shared_from_this())
    );

    // TODO Close the initializationView
    initializationView.reset();

    // Make the view subscribe to updates from the model
    model->subscribe(gameView);

    // Given the 4 player types, create the players in the game
    for (int i = 0; i < 4; i++) {
        if (playerTypes[i] == Player::Type::COMPUTER)
            model->addComputerPlayer(i+1);
        else
            model->addHumanPlayer(i+1);
    }

    // TODO Show the game window

    model->deal();

    // Print a summary of the game before starting
    textView->printObject<Straights>(*model);

    continueGame();
}

void Controller::continueGame(const Command &input) {
    if (input.type == Command::RAGEQUIT) {
        textView->printRagequit(model->returnCurrentPlayer()->getID());
    }

    //TODO Lock game window controlls
    TurnResult turnResult = model->next(input);

    if (turnResult.getType() == TurnResult::REQUIRE_HUMAN_INPUT) {
        // We require more input from the user to complete the round

        // Print the context for the user to decide
        textView->printObject<TurnContext>(model->getTurnContext());

        //TODO Make the view show the player's choices
        //TODO Unlock game window controlls
        return;
    }

    // Print a summary of the move made
    textView->printObject<TurnResult>(turnResult);

    //TODO print the summary of the move on the game window

    if (turnResult.getStatus() == TurnResult::ROUND_COMPLETE ||
        turnResult.getStatus() == TurnResult::GAME_COMPLETE) {

        textView->printObject<RoundContext>(model->getRoundContext());

        // Prepare the next round
        model->clearRound();
        model->deal();

        // Print a summarry of the game
        textView->printObject<Straights>(*model);
    }

    if (turnResult.getStatus() == TurnResult::GAME_COMPLETE) {
        // The game is over
        //TODO Show the game result on the game window & make all buttons unclickable
        return;
    }

    if (model && gameView) {
        // Continue if the game hasn't yet been quit
        continueGame();
    }
}

void Controller::endGame() {
    gameView.reset();
    model.reset();
    initialize();
}
