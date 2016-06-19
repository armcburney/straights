// view.h

#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <iostream>

#include "../Global/Command.h"

class View {
public:
    View(std::istream &inputStream, std::ostream &outputStream);

    template<typename T>
    void printObject(T);
    void initGame();

    Command getCommand() const;

private:
    std::istream& inputStream;
    std::ostream& outputStream;
};

#endif
