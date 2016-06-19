#include <string>
#include <vector>
#include <iostream>
#include <memory>

// Model
#include "Straights.h"
// View
#include "View.h"
// Controller
#include "Controller.h"

using namespace std;

int main () {
    Straights model;
    View view(cin, cout);
    Controller controller(model, view);

    controller.startGame();

    return 0;
}
