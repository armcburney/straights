// view.cpp

#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include <iostream>

View::View(Controller *c, Model *m) : model_(m), controller_(c) {
    model_->subscribe(this); // Register view as observer of model
}

View::~View() {}

void View::nextButtonClicked() {
  controller_->nextButtonClicked();
}
void View::resetButtonClicked() {
  controller_->resetButtonClicked();
}
