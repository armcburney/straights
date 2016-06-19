// controller.h

#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

#include "../Model/Straights.h"
#include "../View/View.h"
#include "../Global/TurnResult.h"

#include <memory>

class Controller {
public:
    Controller(Straights& model, View& view);
    void startGame();

private:
    Straights& model;
    View& view;
};

#endif
