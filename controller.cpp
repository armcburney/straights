// controller.cpp

#include "controller.h"
#include "model.h"

Controller::Controller(Model *m) : model_(m) {}

void Controller::nextButtonClicked() {
    model_->nextCard();
}

void Controller::resetButtonClicked() {
    model_->resetCards();
}
