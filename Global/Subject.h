#ifndef MVC_SUBJECT_H
#define MVC_SUBJECT_H

#include <set>
#include <memory>

template <typename NotificationContext>
class Observer;

template <typename NotificationContext>
class Subject {
public:
       void subscribe( std::shared_ptr<Observer<NotificationContext>> );
       void unsubscribe( std::shared_ptr<Observer<NotificationContext>> );

protected:
       void notifyWithContext(NotificationContext context);
       virtual void notify() = 0;

private:
       std::set< std::shared_ptr<Observer<NotificationContext>> > observers_;
};

#endif

