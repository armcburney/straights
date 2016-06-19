// view.h

#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include "Command.h"
#include <iostream>

class View {
public:
    View(std::istream &inputStream, std::ostream &outputStream);

    template<typename T>
    void printObject(T);

    Command getCommand() const;

private:
    std::istream& inputStream;
    std::ostream& outputStream;
};

#endif
