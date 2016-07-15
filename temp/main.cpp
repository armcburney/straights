#include <iostream>
#include <gtkmm/builder.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

void test () {
  std::cout << "is this working? lmao" << std::endl;
}

int main (int argc, char** argv) {
  Gtk::Main kit(argc, argv);
  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("main.glade");
  Gtk::Window* window;
  builder->get_widget("window1", window);
  window->show();
  kit.run();

  Gtk::Button * button2;
  builder->get_widget("button2", button2);
  button2->signal_clicked().connect( sigc::ptr_fun(&test) );
 // button1->signal_clicked().connect(sigc::mem_fun(*this, &test));
}
