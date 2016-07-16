#include <iostream>
#include <gtkmm/builder.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include "View.h"

using namespace std;

int main (int argc, char** argv) {
  View view(argc, argv);
  cout << "test this" << endl;
}
