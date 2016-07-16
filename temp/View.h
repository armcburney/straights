#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <iostream>
#include <string>
#include <vector>

#include "../Global/Command.h"

class View : public Gtk::Window {
public:
    View(int, char**);
    void test();
};

#endif

