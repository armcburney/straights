#include <cassert>
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

int main (int argc, char *argv[]) {
    assert(argc <= 1);  // assert less than equal since optional command line parameter

    Straights model;
    View view(cin, cout);
    Controller controller(model, view);

    if (argc == 1)
        model.setShuffleSeed(atoi(argv[0]));

    controller.startGame();

    return 0;
}
