#include <iostream>
#include <string>
#include <vector>

#include "Deck.h"
#include "Player.h"
#include "Straights.h"

using namespace std;

Straights::Straights() {
    cout << "init straights" << endl;

    for (int i : {1, 2, 3, 4}) {
        addHumanPlayer(i);
    }
}
void  Straights::addHumanPlayer(int id) {
    Player p = Player(id);
    players.push_back(p);
}
void addComputerPlayer() {

}
void deal() {

}
void next (bool) {

}
