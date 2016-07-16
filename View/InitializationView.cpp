#include <iostream>
#include <string>
#include <vector>

#include "InitializationView.h"
#include "../Controller/Controller.h"

using namespace std;

InitializationView::InitializationView(weak_ptr<Controller> controller)
    : controller(controller) {
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("gui.glade");

    Gtk::Window* w = this;
    builder->get_widget("InitializationView", w);

    Gtk::Button *startGameButton;
    builder->get_widget("startGameButton", startGameButton);
    startGameButton->signal_clicked().connect(
        sigc::mem_fun(*this, &InitializationView::startGameButtonClicked));
}

void InitializationView::startGameButtonClicked() {
    vector<Player::Type> playerTypes = 
        {Player::HUMAN, Player::HUMAN, Player::HUMAN, Player::HUMAN};
    int randomSeed = 0;
    // TODO Get player types and random seed
    if (auto c = controller.lock())
        c->startGame(playerTypes, randomSeed);
}
