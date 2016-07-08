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

int main (void) {
    auto textView = unique_ptr<TextView>(new TextView(cin, cout));
    Controller controller(move(textView));

    controller.initialize();

    return 0;
}
