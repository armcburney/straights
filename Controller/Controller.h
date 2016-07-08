#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

#include "../Model/Straights.h"
#include "../View/TextView.h"
#include "../View/InitializationView.h"
#include "../View/GameView.h"
#include "../Global/TurnResult.h"

#include <memory>
#include <string>

class Controller {
public:
    Controller(std::unique_ptr<Straights> model, std::unique_ptr<TextView> textView);
    void initialize();
    void startGame();
private:
    std::unique_ptr<Straights> model;
    std::unique_ptr<TextView> textView;
    std::unique_ptr<InitializationView> initializationView;
    std::unique_ptr<GameView> gameView;
};

#endif
