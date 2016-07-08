#include <iostream>
#include <string>
#include <vector>

#include "TextView.h"

using namespace std;

TextView::TextView(istream &inputStream, ostream &outputStream)
    : inputStream(inputStream),
      outputStream(outputStream) {}

vector<char> TextView::getPlayerTypes() {
    vector<char> players;
    char player;

    for (int i = 0; i < 4; i++) {
        outputStream << "Is player " << i+1 << " a human(h) or a computer(c)?" << endl;
        outputStream << ">";
        inputStream >> player;
        players.push_back(player);
    }
    inputStream.ignore();

    return players;
}

void TextView::printNewLine() {
    outputStream << endl;
}

void TextView::printRagequit(int id) {
    cout << "Player " << id << " ragequits. A computer will now take over." << endl;
}

Command TextView::getCommand() {
    outputStream << ">";

    Command cmd;
    inputStream >> cmd;
    return cmd;
}
