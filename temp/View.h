#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <iostream>
#include <string>
#include <vector>

#include "gtkmm.h"
#include "../Global/Command.h"

class View : public Gtk::Window {
public:
    View();
    void temp();
    void rage();
private:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Button * button1, *button2;
};

#endif

