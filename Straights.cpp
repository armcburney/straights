#include <iostream>
#include <string>
#include <vector>

#include "Deck.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Straights.h"

using namespace std;

/* Constructor */
Straights::Straights() : currentPlayer(1), currentRound(0) {
    for (int i : {1, 2, 3, 4}) {
        addHumanPlayer(i);
    }

    // /* Deck */
    // for (auto i : deck.cards()) {
    //     cout << *i << " ";
    // } cout << endl;

    // do the shuffle here lol
    // deal();
}

/* Adds a human player */
void Straights::addHumanPlayer (int id) {
    HumanPlayer p = HumanPlayer(id);
    players.push_back(p);
}
/* Adds a computer player */
void Straights::addComputerPlayer (int id) {
    ComputerPlayer p = ComputerPlayer(id);
    players.push_back(p);
}
/* Deals the cards to players 1 to 4 */
void Straights::deal () {
    for (auto i : deck.cards()) {
        cout << *i << " ";
    } cout << endl;
    deck.shuffle();
    for (auto i : deck.cards()) {
        cout << *i << " ";
    } cout << endl;
}

/* Initiates next round */
void next (bool) {

}
