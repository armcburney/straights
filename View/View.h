// view.h

#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <iostream>
#include <string>
#include <vector>

#include "../Global/Command.h"

class View {
public:
    View(std::istream &inputStream, std::ostream &outputStream);

    std::vector<char> getPlayers();

    template<typename T>
    void printObject(T object) { outputStream << object; };

    Command getCommand();

private:
    std::istream& inputStream;
    std::ostream& outputStream;
};

#endif
