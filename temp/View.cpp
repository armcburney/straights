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
    builder = Gtk::Builder::create_from_file("main.glade");
    Gtk::Window* window;
    builder->get_widget("window1", window);
    window->show();

    Gtk::Button * button1, *button2;
    builder->get_widget("button1", button1);
    builder->get_widget("button2", button2);
    button1->signal_clicked().connect(sigc::mem_fun(*this, &View::temp));
    button2->signal_clicked().connect(sigc::mem_fun(*this, &View::rage));
}

void View::rage() {
  cout << "ragequit" << endl;
  //const GdkColor * color;
  //gdk_color_parse("#A22222", color);
  //gtk_widget_override_color (GTK_WIDGET(button1), GTK_STATE_FLAG_NORMAL, color);
}


void View::temp() {
  cout << "test if this bad boy is working or not" << endl;
  //Gtk::TextBuffer* buffer;
  Gtk::Image * image;
  builder->get_widget("image1", image);
  GtkImage *image2 = image->gobj();
  gtk_image_set_from_file(image2, "cards_png/KD.png");
  /*builder->get_widget("textbuffer1", buffer);
  GtkTextBuffer* buffer2 = buffer->gobj();
  gtk_text_buffer_set_text (buffer2, "test", 4);*/
}

