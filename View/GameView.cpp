#include <iostream>
#include <string>
#include <vector>

#include "GameView.h"
#include "../Controller/Controller.h"

using namespace std;

GameView::GameView(BaseObjectType *cObject, const Glib::RefPtr<Gtk::Builder>&)
    : Gtk::Window(cObject),
      selectedCardIndex(-1) {

    // TODO Hook up buttons
}

void GameView::setController(weak_ptr<Controller> c) {
    controller = c;
}

void GameView::update(RoundContext) {
    // TODO Update the view with content from context
    cout << "Updating the game view" << endl;
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
