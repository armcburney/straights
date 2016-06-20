// view.cpp

#include <iostream>
#include <string>
#include <vector>

#include "View.h"

using namespace std;

View::View(istream &inputStream, ostream &outputStream)
    : inputStream(inputStream),
      outputStream(outputStream) {}

vector<char> View::getPlayers() {
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

void View::printNewLine() {
    outputStream << endl;
}

void View::printRagequit(int id) {
    cout << "Player " << id << " ragequits. A computer will now take over." << endl;
}

Command View::getCommand() {
    outputStream << ">";

    Command cmd;
    inputStream >> cmd;
    return cmd;
}
