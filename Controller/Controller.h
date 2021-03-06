#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

#include "../Model/Straights.h"
#include "../View/TextView.h"
#include "../View/InitializationView.h"
#include "../View/GameView.h"
#include "../Global/TurnResult.h"
#include "../Global/Observer.h"
#include "../Global/Context.h"

#include <memory>
#include <string>

class Controller : public std::enable_shared_from_this<Controller> {
public:
    Controller(std::unique_ptr<TextView> textView);
    void initialize();                                      // Show the window to start a game
    void startGame(std::vector<Player::Type>, int seed);
    void continueGame(const Command &input = Command());
    void endGame();
    void quit();
private:
    std::unique_ptr<Straights> model;
    std::unique_ptr<TextView> textView;                     // Used to access cout / cin
    std::unique_ptr<InitializationView> initializationView;
    std::shared_ptr<GameView> gameView;

    Glib::RefPtr<Gtk::Builder> gladeBuilder;                // GUI builder
    Gtk::MessageDialog *gameOverDialog;                     // Dialog to indicate winner
};

#endif
