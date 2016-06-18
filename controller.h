// controller.h

#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

class Model;

class Controller {
public:
    Controller( Model* );
    void nextButtonClicked();
    void resetButtonClicked();
private:
    Model *model_;
};

#endif
