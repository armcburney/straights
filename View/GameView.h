#ifndef MVC_GAME_VIEW_H
#define MVC_GAME_VIEW_H

#include <gtkmm.h>
#include <iostream>
#include <string>
#include <vector>

#include "../Global/Command.h"
#include "../Global/Observer.h"
#include "../Global/Context.h"

class Controller;

class GameView : public Gtk::Window, public Observer<RoundContext> {
public:
    GameView(std::weak_ptr<Controller>);
    virtual void update(RoundContext context) final;
private:
    std::weak_ptr<Controller> controller;
};

#endif
