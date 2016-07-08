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
    Controller(unique_ptr<Straights> model, unique_ptr<TextView> textView);
    void initialize();
    void startGame();
private:
    unique_ptr<Straights> model;
    unique_ptr<TextView> textView;
    unique_ptr<InitializationView> textView;
};

#endif
