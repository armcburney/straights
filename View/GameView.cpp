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

    builder->get_widget("playButton", playButton);
    builder->get_widget("discardButton", discardButton);
    builder->get_widget("rageQuitButton", rageQuitButton);

    builder->get_widget("summaryTextView", statusTextView);
    builder->get_widget("currentPlayerLabel", currentPlayerLabel);
    builder->get_widget("currentCardLabel", currentCardLabel);

    // Create mappings for the player's move options
    for (int i = 0; i < 13; i++) {
        builder->get_widget("handCardImage" + to_string(i+1), handCardImages[i]);
        builder->get_widget("handCard" + to_string(i+1), handCardButtons[i]);

        handCardButtons[i]->signal_clicked().connect([this, i]() {
            cardSelected(i);
        });
    }

    // Create mappings for cards on the table
    for (int i = 0; i < 54; i++) {
        builder->get_widget("Table" + to_string(i+1), tableCards[i]);
    }

    // Create mappings for player's hand & scores
    for (int i = 0; i < 4; i++) {
        builder->get_widget("p" + to_string(i+1) + "Score", playerScoreLabels[i]);
        for (int j = 0; j < 13; j++) {
            builder->get_widget("P" + to_string(i+1) + "_C" + to_string(j+1), playerHands[i][j]);
        }
    }

    playButton->signal_clicked().connect(
        sigc::mem_fun(*this, &GameView::playButtonClicked));
    discardButton->signal_clicked().connect(
        sigc::mem_fun(*this, &GameView::discardButtonClicked));
    rageQuitButton->signal_clicked().connect(
        sigc::mem_fun(*this, &GameView::rageQuitButtonClicked));

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

    // Update the gamePile in the UI
    int i = 0;
    for (auto card : rc.gamePile) {
        GtkImage *cardImage = tableCards[i]->gobj();
        gtk_image_set_from_file(cardImage, card->getImageUrl().c_str());
        i++;
    }

    for (int i = 0; i < 4; i++) {
        // Update the player's hands
        vector<TurnResult> playerRoundMoves = rc.playerRoundMoves[i];
        for (int j = 0; j < 13; j++) {
            GtkImage *image = playerHands[i][j]->gobj();

            string cardImage = "View/CardImages/back.png";
            try {
                TurnResult tr = playerRoundMoves.at(j);
                if (tr.getType() == TurnResult::PLAY)
                    cardImage = "View/CardImages/none.png";
                else if (tr.getType() == TurnResult::DISCARD)
                    cardImage = "View/CardImages/discard.png";
            } catch(out_of_range&) {}

            gtk_image_set_from_file(image, cardImage.c_str());
        }

        // Update the player's scores
        Score score = rc.playerScores[i];
        string scoreStr = to_string(score.toInt());
        playerScoreLabels[i]->set_label(scoreStr);
    }
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
    if (selectedCardIndex == -1)
        return;

    Card card = *(hand[selectedCardIndex]);
    Command input(Command::PLAY, card);
    if (auto c = controller.lock())
        c->continueGame(input);

    // Reset selected card
    selectedCardIndex = -1;
}

void GameView::discardButtonClicked() {
    if (selectedCardIndex == -1)
        return;

    Card card = *(hand[selectedCardIndex]);
    Command input(Command::DISCARD, card);
    if (auto c = controller.lock())
        c->continueGame(input);

    // Reset selected card
    selectedCardIndex = -1;
}

void GameView::rageQuitButtonClicked() {
    Command input(Command::RAGEQUIT);
    if (auto c = controller.lock())
        c->continueGame(input);

    // Reset selected card
    selectedCardIndex = -1;
}

void GameView::windowClosed() {
    if (auto c = controller.lock())
        c->endGame();
}

void GameView::printTurnResult(const TurnResult &tr) {
    stringstream ss;
    ss << tr;

    // Add this to the text view buffer
    Glib::RefPtr< Gtk::TextBuffer > textBuffer = statusTextView->get_buffer();
    textBuffer->insert(textBuffer->begin(), ss.str());
}

void GameView::printRoundContext(const RoundContext &rc) {
    stringstream ss;
    ss << rc;

    // Replace the text buffer
    Glib::RefPtr< Gtk::TextBuffer > textBuffer = statusTextView->get_buffer();
    textBuffer->erase(textBuffer->begin(), textBuffer->end());
    textBuffer->insert(textBuffer->end(), ss.str());
}

void GameView::printGameSummary(const Straights &straights) {
    stringstream ss;
    ss << endl << straights << endl;

    // Add this to the text view buffer
    Glib::RefPtr< Gtk::TextBuffer > textBuffer = statusTextView->get_buffer();
    textBuffer->insert(textBuffer->begin(), ss.str());
}

void GameView::printTurnContext(const TurnContext &tc) {
    hand.clear();
    copy(tc.hand.begin(), tc.hand.end(), back_inserter(hand));

    if (!tc.legalPlays.empty()) {
        // This move will be a "Play"
        playButton->set_sensitive(true);
        discardButton->set_sensitive(false);
    } else {
        // This move will be a "Discard"
        playButton->set_sensitive(false);
        discardButton->set_sensitive(true);
    }

    for (int i = 0; i < 13; i++) {
        GtkImage *cardImage = handCardImages[i]->gobj();
        try {
            CardPtr card = hand.at(i);
            gtk_image_set_from_file(cardImage, card->getImageUrl().c_str());

            if (tc.legalPlays.empty()) {
                // If no legal plays, we can discard any card
                handCardButtons[i]->set_sensitive(true);
            } else {
                // Disable the card if it is not valid
                auto legalPlay = find_if(
                    tc.legalPlays.begin(),
                    tc.legalPlays.end(),
                    [card] (CardPtr c) {
                        return *c == *card;
                    }
                );
                handCardButtons[i]->set_sensitive(legalPlay != tc.legalPlays.end());
            }
        } catch (out_of_range&) {
            // If the hand size < 13, display disabled card backs
            gtk_image_set_from_file(cardImage, "View/CardImages/none.png");
            handCardButtons[i]->set_sensitive(false);
        }
    }
}
