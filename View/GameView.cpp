#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "GameView.h"
#include "../Controller/Controller.h"

using namespace std;

GameView::GameView(BaseObjectType *cObject, const Glib::RefPtr<Gtk::Builder> &builder)
    : Gtk::Window(cObject),
      selectedCardIndex(-1) {

    builder->get_widget("statusTextView", statusTextView);

    Gtk::Button *playButton;
    builder->get_widget("playButton", playButton);
    playButton->signal_clicked().connect(
        sigc::mem_fun(*this, &GameView::playButtonClicked));

    this->signal_hide().connect(
        sigc::mem_fun(*this, &GameView::windowClosed));
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

void GameView::windowClosed() {
    if (auto c = controller.lock())
        c->endGame();
}

void GameView::printTurnResult(TurnResult tr) {
    stringstream ss;
    ss << tr;

    // Add this to the text view buffer
    Glib::RefPtr< Gtk::TextBuffer > textBuffer = statusTextView->get_buffer();
    textBuffer->insert(textBuffer->end(), ss.str());
}

void GameView::printTurnContext(TurnContext tc) {
    // TODO show the player's hand
}
