#include <set>
#include "Subject.h"
#include "Observer.h"

using namespace std;

template <typename NotificationContext>
void Subject<NotificationContext>::subscribe (shared_ptr<Observer<NotificationContext>> newView) {
    observers_.insert(newView);
}


template <typename NotificationContext>
void Subject<NotificationContext>::unsubscribe (shared_ptr<Observer<NotificationContext>> formerView) {
    observers_.erase(formerView);
}


template <typename NotificationContext>
void Subject<NotificationContext>::notify(NotificationContext context) {
    for (auto i = observers_.begin(); i != observers_.end(); ++i)
        (*i)->update(context);
}
