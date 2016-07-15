#include <iostream>
#include <gtkmm/builder.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

int main (int argc, char** argv) {
  std::cout << "Init..." << std::endl;
  Gtk::Main kit(argc, argv);
  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("main.glade");
  Gtk::Window* window;
  builder->get_widget("window1", window);
  std::cout << "Set up window..." << std::endl;
  window->show();
  kit.run();
}

