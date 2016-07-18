#include "Subject.h"
#include "Observer.h"

using namespace std;

// New Observer
template <typename NotificationContext>
void Subject<NotificationContext>::subscribe (shared_ptr<Observer<NotificationContext>> newView) {
    observers_.insert(newView);
}


// Remove Observer
template <typename NotificationContext>
void Subject<NotificationContext>::unsubscribe (shared_ptr<Observer<NotificationContext>> formerView) {
    observers_.erase(formerView);
}


// Notify Observers
template <typename NotificationContext>
void Subject<NotificationContext>::notifyWithContext(NotificationContext context) {
    for (auto i = observers_.begin(); i != observers_.end(); ++i)
        (*i)->update(context);
}
