#ifndef __DECK_GUI_H
#define __DECK_GUI_H
#include <gdkmm/pixbuf.h>
#include <vector>
using std::vector;

#include "model.h"

class MainGUI {
public:
	MainGUI();
	virtual ~MainGUI();
	Glib::RefPtr<Gdk::Pixbuf> image( Faces f, Suits s ); 
	Glib::RefPtr<Gdk::Pixbuf> null();

private:
	vector< Glib::RefPtr< Gdk::Pixbuf > > deck;
};
#endif

