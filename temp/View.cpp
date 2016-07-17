#include <iostream>
#include <string>
#include <vector>
#include <gtkmm/builder.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/cssprovider.h>

#include "View.h"

using namespace std;

View::View() {
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    
    builder = Gtk::Builder::create_from_file("main.glade");
    Gtk::Window* window;
    builder->get_widget("window1", window);
    window->show();

    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gsize bytes_written, bytes_read;

    const gchar* home = "styles.css";
    GError *error = 0;

    gtk_css_provider_load_from_path (provider, g_filename_to_utf8(home, strlen(home), &bytes_read, &bytes_written, &error), NULL);
    g_object_unref (provider);

    builder->get_widget("button1", button1);
    builder->get_widget("button2", button2);
    button1->signal_clicked().connect(sigc::mem_fun(*this, &View::temp));
    button2->signal_clicked().connect(sigc::mem_fun(*this, &View::rage));
}

void View::rage() {
  cout << "ragequit" << endl;
  GdkColor color;
  gdk_color_parse("red", &color);
//  gtk_widget_override_background_color(GTK_WIDGET(button2), GTK_STATE_NORMAL, &color);
}


void View::temp() {
  Gtk::Image * image;
  builder->get_widget("image1", image);
  GtkImage *image2 = image->gobj();
  gtk_image_set_from_file(image2, "cards_png/KD.png");
  //Gtk::TextBuffer* buffer;
  /*builder->get_widget("textbuffer1", buffer);
  GtkTextBuffer* buffer2 = buffer->gobj();
  gtk_text_buffer_set_text (buffer2, "test", 4);*/
}

