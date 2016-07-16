#include <iostream>
#include <string>
#include <vector>
#include <gtkmm/builder.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

#include "View.h"

using namespace std;

View::View() {
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("main.glade");
    Gtk::Window* window;
    builder->get_widget("window1", window);
    window->show();

    Gtk::Button * button1 = new Gtk::Button("button1");
    builder->get_widget("button1", button1);
    button1->signal_clicked().connect(sigc::mem_fun(*this, &View::test));
}

void View::test() {
  cout << "test if this bad boy is working or not" << endl;
}

