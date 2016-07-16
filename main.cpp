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

int main (int argc, char** argv) {
    std::cout << "Init..." << std::endl;
    Gtk::Main kit(argc, argv);
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("main.glade");
    Gtk::Window* window;
    builder->get_widget("window1", window);
    std::cout << "Set up window..." << std::endl;
    window->show();
    kit.run();

    auto textView = unique_ptr<TextView>(new TextView(cin, cout));
    auto controller = shared_ptr<Controller>(new Controller(move(textView)));

    controller->initialize();
    return 0;
}
