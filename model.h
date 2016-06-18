// model.h

#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"

class Model : public Subject {
public:
    Model();
    void nextCard();
    void resetCards();
private:
    int topCard_;
};

#endif
