#include <iostream>
#include <string>
#include <vector>
#include <gtkmm/builder.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

#include "View.h"

using namespace std;

View::View() {
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("main.glade");
    Gtk::Window* window;
    builder->get_widget("window1", window);
    window->show();

    Gtk::Button * button1;
    builder->get_widget("button1", button1);
    button1->signal_clicked().connect([&] () {
        return temp(builder);
    });
}

void View::temp(Glib::RefPtr<Gtk::Builder> builder) {
  cout << "test if this bad boy is working or not" << endl;
  //const GdkColor * color;
  //gdk_color_parse("#A22222", color);
  //gtk_widget_override_color (GTK_WIDGET(button1), GTK_STATE_FLAG_NORMAL, color);
 // Gtk::TextView* text;
 // GtkTextBuffer* buffer;
  GtkImage * image;
  builder->get_widget("image1", image);
  gtk_image_set_from_file(image, "cards_png/KD.png");
 // builder->get_widget("textview1", text);
  //builder->get_widget("textbuffer1", buffer);
//gtk_text_buffer_set_text (GtkTextBuffer buffer,
   //                       "test", 4);
}

