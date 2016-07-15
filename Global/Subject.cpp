#include <set>
#include "Subject.h"
#include "Observer.h"

using namespace std;

void Subject::subscribe (shared_ptr<Observer> newView) {
    observers_.insert(newView);
}


void Subject::unsubscribe (shared_ptr<Observer> formerView) {
     observers_.erase(formerView);
}


void Subject::notify() {
  Observers::iterator i;
  for (i = observers_.begin(); i != observers_.end(); ++i)
    (*i)->update();
}
