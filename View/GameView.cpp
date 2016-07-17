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
    builder->get_widget("currentPlayerLabel", currentPlayerLabel);
    builder->get_widget("currentCardLabel", currentCardLabel);

    for (int i = 0; i < 13; i++) {
        builder->get_widget("handCard" + to_string(i+1), handCards[i]);
        handCards[i]->signal_grab_focus().connect([&]() {
            cardSelected(i);
        });
    }

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

void GameView::update(RoundContext rc) {
    stringstream currentPlayerMessage;
    currentPlayerMessage << "It's Player " << rc.currentPlayerId << "'s turn to play!";
    currentPlayerLabel->set_label(currentPlayerMessage.str());
}

void GameView::cardSelected(int index) {
    selectedCardIndex = index;

    // Update the label indicating the current card
    CardPtr currentCard = hand[index];
    stringstream currentCardMessage;
    currentCardMessage << "Current card: " << *currentCard;
    currentCardLabel->set_label(currentCardMessage.str());
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
    hand.clear();
    copy(tc.hand.begin(), tc.hand.end(), back_inserter(hand));

    for (int i = 0; i < 13; i++) {
        CardPtr card = hand[i];
        GtkImage *btn = handCards[i]->gobj();
        gtk_image_set_from_file(btn, card->getImageUrl().c_str());
    }
}
