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
    GameView(BaseObjectType *cObject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual void update(RoundContext context) final;
    void setController(std::weak_ptr<Controller>);
private:
    std::weak_ptr<Controller> controller;
    int selectedCardIndex;
    std::vector<CardPtr> hand;

    void cardSelected(int index);
    void playButtonClicked();
    void discardButtonClicked();
    void rageQuitButtonClicked();
};

#endif
