// view.h

#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include "observer.h"

class Controller;
class Model;

class View : public Observer {
public:
    View(Controller*, Model*);
	virtual ~View();
	virtual void update();	    // Observer Pattern

private:
	Model *model_;             // Observer Pattern
	Controller *controller_;   // Strategy Pattern

	// Signal handlers:
	void nextButtonClicked();
	void resetButtonClicked();
};

#endif
