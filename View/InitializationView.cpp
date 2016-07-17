#include <iostream>
#include <string>
#include <vector>

#include "InitializationView.h"
#include "../Controller/Controller.h"

using namespace std;

InitializationView::InitializationView(BaseObjectType *cObject, const Glib::RefPtr<Gtk::Builder>& builder) 
    : Gtk::Window(cObject) {

    Gtk::Button *startGameButton;
    builder->get_widget("startGameButton", startGameButton);
    startGameButton->signal_clicked().connect(
        sigc::mem_fun(*this, &InitializationView::startGameButtonClicked));

    this->signal_hide().connect(
        sigc::mem_fun(*this, &InitializationView::windowClosed));
}

void InitializationView::setController(weak_ptr<Controller> c) {
    controller = c;
}

void InitializationView::startGameButtonClicked() {
    vector<Player::Type> playerTypes = 
        {Player::HUMAN, Player::HUMAN, Player::HUMAN, Player::HUMAN};
    int randomSeed = 0;
    // TODO Get player types and random seed
    if (auto c = controller.lock())
        c->startGame(playerTypes, randomSeed);
    else
        cerr << "Controller no longer exists!" << endl;
}

void InitializationView::windowClosed() {
    if (auto c = controller.lock())
        c->quit();
}
