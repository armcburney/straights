#ifndef MVC_INITIALIZATION_VIEW_H
#define MVC_INITIALIZATION_VIEW_H

#include <gtkmm.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <array>

#include "../Global/Command.h"
#include "../Global/Observer.h"
#include "../Global/Context.h"

class Controller;

class InitializationView : public Gtk::Window {
public:
    InitializationView(BaseObjectType*, const Glib::RefPtr<Gtk::Builder>&);
    void setController(std::weak_ptr<Controller>);
private:
    std::weak_ptr<Controller> controller;
    void startGameButtonClicked();
    void playerTypeChanged(int, bool);
    void windowClosed();

    std::array<std::pair<Gtk::CheckButton*, Gtk::CheckButton*>, 4> playerTypeCheckboxes;
    Gtk::Entry *randomSeedEntry;
};

#endif
