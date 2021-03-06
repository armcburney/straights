#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <iostream>
#include <string>
#include <vector>

#include "../Global/Command.h"

class TextView {
public:
    TextView(std::istream &inputStream, std::ostream &outputStream);
    /*
    POSTCONDITIONS:
      - ensures: initializes this to a TextView with input and output stream
    */
    std::vector<char> getPlayerTypes();
    /*
    POSTCONDITIONS:
      - returns: a vector of player types for four players provided by the user
    */
    template<typename T>
    void printObject(const T &object) { outputStream << object; };
    /*
    PRECONDITIONS:
      - requires: a printable object
    POSTCONDITIONS:
      - modifies: this
    */
    void printNewLine();
    /*
    POSTCONDITIONS:
      - modifies: this
    */
    void printRagequit(int);
    /*
    PRECONDITIONS:
      - requires: an integer player id
    POSTCONDITIONS:
      - modifies: this
    */
    Command getCommand();
    /*
    POSTCONDITIONS:
      - returns: a command asked from the user
    */

private:
    std::istream& inputStream;
    std::ostream& outputStream;
};

#endif
