// view.cpp

#include "View.h"
#include <iostream>

using namespace std;

View::View(istream &inputStream, ostream &outputStream)
    : inputStream(inputStream),
      outputStream(outputStream) {}

template<typename T>
void View::printObject(T object) {
    outputStream << object;
}

Command View::getCommand() const {
    Command cmd;
    inputStream >> cmd;
    return cmd;
}