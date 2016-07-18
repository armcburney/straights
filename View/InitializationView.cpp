#include <iostream>
#include <string>
#include <vector>

#include "InitializationView.h"
#include "../Controller/Controller.h"

using namespace std;

InitializationView::InitializationView(BaseObjectType *cObject, const Glib::RefPtr<Gtk::Builder>& builder) 
    : Gtk::Window(cObject) {

    // Create mapping for seed text entry
    builder->get_widget("randomSeedEntry", randomSeedEntry);

    // Create mappings & click handlers for Human / Computer checkboxes
    for (int i = 0; i < 4; i++) {
        builder->get_widget(
            "p" + to_string(i+1) + "HumanCheckbox", playerTypeCheckboxes[i].first);
        builder->get_widget(
            "p" + to_string(i+1) + "ComputerCheckbox", playerTypeCheckboxes[i].second);

        playerTypeCheckboxes[i].first->signal_clicked().connect(
            [this, i]() { playerTypeChanged(i, true); });
        playerTypeCheckboxes[i].second->signal_clicked().connect(
            [this, i]() { playerTypeChanged(i, false); });
    }

    // Create handler for starting the game
    Gtk::Button *startGameButton;
    builder->get_widget("startGameButton", startGameButton);
    startGameButton->signal_clicked().connect(
        sigc::mem_fun(*this, &InitializationView::startGameButtonClicked));

    // Create handler for closing the window
    this->signal_hide().connect(
        sigc::mem_fun(*this, &InitializationView::windowClosed));
}

void InitializationView::setController(weak_ptr<Controller> c) {
    controller = c;
}

void InitializationView::startGameButtonClicked() {
    vector<Player::Type> playerTypes;
    int randomSeed = 0;

    // Start the game with human/computer players selected
    transform(
        playerTypeCheckboxes.begin(),
        playerTypeCheckboxes.end(),
        back_inserter(playerTypes),
        [] (const pair<Gtk::CheckButton*,Gtk::CheckButton*> &p) {
            return (p.first->get_active()) ? Player::HUMAN : Player::COMPUTER;
        }
    );
    randomSeed = stoi(randomSeedEntry->get_text());

    if (auto c = controller.lock())
        c->startGame(playerTypes, randomSeed);
    else
        cerr << "Controller no longer exists!" << endl;
}

void InitializationView::playerTypeChanged(int playerIndex, bool humanToggled) {
    Gtk::CheckButton *hb = playerTypeCheckboxes[playerIndex].first;
    Gtk::CheckButton *cb = playerTypeCheckboxes[playerIndex].second;

    // Ensures that one checkbox is selected for pair of checkboxes
    if (humanToggled) {
        bool isHuman = hb->get_active();
        if (cb->get_active() == isHuman)
            cb->set_active(!isHuman);
    } else {
        bool isComputer = cb->get_active();
        if (hb->get_active() == isComputer)
            hb->set_active(!isComputer);
    }
}

void InitializationView::windowClosed() {
    // Quit the game on window close
    if (auto c = controller.lock())
        c->quit();
}
