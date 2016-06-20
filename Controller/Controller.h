// controller.h

#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

#include "../Model/Straights.h"
#include "../View/View.h"
#include "../Global/TurnResult.h"

#include <memory>
#include <string>

class Controller {
public:
    Controller(Straights& model, View& view);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a Command with:
        Straights& = model
        View& = view
    */
    void startGame();
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a Command with:
        type = NO_COMMAND
        card = Ace of spades
    */
private:
    Straights& model;
    View& view;
};

#endif
