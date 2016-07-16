#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "gtkmm.h"

// Model
#include "Model/Straights.h"
// View
#include "View/TextView.h"
// Controller
#include "Controller/Controller.h"

using namespace std;

int main (int argc, char** argv) {
    Gtk::Main kit(argc, argv);

    auto textView = unique_ptr<TextView>(new TextView(cin, cout));
    auto controller = shared_ptr<Controller>(new Controller(move(textView)));

    controller->initialize();

    kit.run();
    return 0;
}
