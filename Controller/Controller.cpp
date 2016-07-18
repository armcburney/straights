#include <vector>
#include <iostream>

#include "Controller.h"
#include "../Model/Deck.h"

#include "../Global/Subject.cpp"

using namespace std;

Controller::Controller(unique_ptr<TextView> textView)
    : textView(move(textView)) {}

void Controller::initialize() {
    gladeBuilder = Gtk::Builder::create_from_file("View/gui.glade");

    // Show the initialization window
    InitializationView *iv;
    gladeBuilder->get_widget_derived("InitializationView", iv);
    initializationView = unique_ptr<InitializationView>(iv);
    initializationView->setController(shared_from_this());
    initializationView->show();
}

void Controller::startGame(vector<Player::Type> playerTypes, int randomSeed) {
    // Create the game model
    model = unique_ptr<Straights>(new Straights(randomSeed));

    // Close the initializationView
    initializationView.reset();

    // Show the game window
    GameView *gv;
    gladeBuilder->get_widget_derived("GameView", gv);
    gameView = shared_ptr<GameView>(gv);
    gameView->setController(shared_from_this());
    gameView->show();

    // Make the view subscribe to updates from the model
    model->subscribe(gameView);

    // Given the 4 player types, create the players in the game
    for (int i = 0; i < 4; i++) {
        if (playerTypes[i] == Player::Type::COMPUTER)
            model->addComputerPlayer(i+1);
        else
            model->addHumanPlayer(i+1);
    }

    model->deal();

    // Print a summary of the game before starting
    textView->printObject<Straights>(*model);

    continueGame();
}

void Controller::continueGame(const Command &input) {
    if (input.type == Command::RAGEQUIT) {
        model->automateCurrentPlayer();
        textView->printRagequit(model->returnCurrentPlayer()->getID());
    }

    //TODO Lock game window controlls
    TurnResult turnResult = model->next(input);

    if (turnResult.getType() == TurnResult::REQUIRE_HUMAN_INPUT) {
        // We require more input from the user to complete the round

        // Print the context for the user to decide
        TurnContext turnContext = model->getTurnContext();
        textView->printObject<TurnContext>(turnContext);
        gameView->printTurnContext(turnContext);

        //TODO Unlock game window controlls
        return;
    }

    // Print a summary of the move made
    textView->printObject<TurnResult>(turnResult);
    gameView->printTurnResult(turnResult);

    if (turnResult.getStatus() == TurnResult::ROUND_COMPLETE ||
        turnResult.getStatus() == TurnResult::GAME_COMPLETE) {

        // Print a summary of the round
        RoundContext roundContext = model->getRoundContext();
        textView->printObject<RoundContext>(roundContext);
        gameView->printRoundContext(roundContext);

        // Prepare the next round
        model->clearRound();
        model->deal();

        // Print a summarry of the game
        textView->printObject<Straights>(*model);
        gameView->printGameSummary(*model);
    }

    if (turnResult.getStatus() == TurnResult::GAME_COMPLETE) {
        std::string test = "Winner(s): player " + model->returnWinner(*model) + ".";
        const char * temp = test.c_str();

        // The game is over
        Gtk::MessageDialog *dialog;
        gladeBuilder->get_widget("GameSummaryView", dialog);
        GtkMessageDialog *run_dialog = dialog->gobj();
        gtk_message_dialog_set_markup (run_dialog, temp); 
        gtk_dialog_run(GTK_DIALOG(run_dialog));
        return;
    }

    // Continue if the game hasn't yet been quit
    if (model && gameView) {
        // Allow UI to handle events before continuing
        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();

        continueGame();
    }
}

void Controller::endGame() {
    gameView.reset();
    model.reset();
    initialize();
}

void Controller::quit() {
    initializationView.reset();
    gameView.reset();
    model.reset();
    exit(0);
}
