#include <string>
#include <vector>
#include <iostream>
#include <memory>

// Model
#include "Model/Straights.h"
// View
#include "View/View.h"
// Controller
#include "Controller/Controller.h"

using namespace std;

int main () {
    Straights model;
    View view(cin, cout);
    Controller controller(model, view);

    controller.startGame();

    return 0;
}
