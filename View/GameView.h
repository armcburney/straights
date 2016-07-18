#ifndef MVC_GAME_VIEW_H
#define MVC_GAME_VIEW_H

#include <gtkmm.h>
#include <iostream>
#include <string>
#include <vector>

#include "../Model/Straights.h"

#include "../Global/Command.h"
#include "../Global/Observer.h"
#include "../Global/Context.h"
#include "../Global/TurnResult.h"

class Controller;

class GameView : public Gtk::Window, public Observer<RoundContext> {
public:
    GameView(BaseObjectType *cObject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual void update(RoundContext context) final;
    void setController(std::weak_ptr<Controller>);

    void printTurnResult(const TurnResult&);
    void printTurnContext(const TurnContext&);
    void printRoundContext(const RoundContext&);
    void printGameSummary(const Straights&);
private:
    std::weak_ptr<Controller> controller;
    int selectedCardIndex;
    std::vector<CardPtr> hand;

    void cardSelected(int index);
    void playButtonClicked();
    void discardButtonClicked();
    void rageQuitButtonClicked();
    void windowClosed();

    Gtk::Button *playButton;
    Gtk::Button *discardButton;
    Gtk::Button *rageQuitButton;

    Gtk::TextView *statusTextView;
    Gtk::Label *currentPlayerLabel;
    Gtk::Label *currentCardLabel;

    std::array<Gtk::Button*, 13> handCardButtons;
    std::array<Gtk::Image*, 13> handCardImages;

    std::array<Gtk::Image*, 54> tableCards;
    std::array<std::array<Gtk::Image*, 13>, 54> playerHands;
    std::array<Gtk::Label*, 4> playerScoreLabels;
};

#endif
