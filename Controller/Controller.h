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
      - ensures: initializes this to a Controller with:
        - Straights& = model
        - View& = view
    */
    void startGame();
    /*
    POSTCONDITIONS:
      - modifies:
        - View: with output from the game
        - Model: width statistics and properties of the game
      - ensures: that the game finishes, players are added to the model,
        and the deck is shuffled, and dealt
    */
private:
    Straights& model;
    View& view;
};

#endif
