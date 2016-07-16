#include <iostream>
#include <string>
#include <vector>

#include "GameView.h"
#include "../Controller/Controller.h"

using namespace std;

GameView::GameView(weak_ptr<Controller> controller)
    : controller(controller),
      selectedCardIndex(-1) {
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("View/gui.glade");

    Gtk::Window* w = this;
    builder->get_widget("GameView", w);
}

void GameView::update(RoundContext) {
    // TODO Update the view with content from context
}

void GameView::cardSelected(int index) {
    selectedCardIndex = index;
    // TODO Update the text in the view to indicate the selected card
}

void GameView::playButtonClicked() {
    Card card = *(hand[selectedCardIndex]);
    Command input(Command::PLAY, card);
    if (auto c = controller.lock())
        c->continueGame(input);
}

void GameView::discardButtonClicked() {
    Card card = *(hand[selectedCardIndex]);
    Command input(Command::DISCARD, card);
    if (auto c = controller.lock())
        c->continueGame(input);
}

void GameView::rageQuitButtonClicked() {
    Command input(Command::RAGEQUIT);
    if (auto c = controller.lock())
        c->continueGame(input);
}
