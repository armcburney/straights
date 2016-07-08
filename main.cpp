#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

// Model
#include "Model/Straights.h"
// View
#include "View/TextView.h"
// Controller
#include "Controller/Controller.h"

using namespace std;

int main (int argc, char *argv[]) {
    assert(argc <= 2);  // assert less than equal since optional command line parameter

    unique_ptr<Straights> model;
    unique_ptr<TextView> textView = new TextView(cin, cout);
    Controller controller(model, textView);

    controller.initialize();

    return 0;
}
