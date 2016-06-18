#include <string>
#include <vector>
#include <iostream>

#include "Straights.h"

// MVC
#include "model.h"
#include "controller.h"
#include "view.h"

using namespace std;

int main () {
    cout << "init" << endl;
    Straights s = Straights();
    cout << "end" << endl;

    return 0;
}
