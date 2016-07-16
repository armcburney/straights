#include <iostream>
#include <string>
#include <vector>

#include "GameView.h"

using namespace std;

GameView::GameView(weak_ptr<Controller> controller)
    : controller(controller) {
    // TODO Load glade template
}
