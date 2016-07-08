#ifndef MVC_SUBJECT_H
#define MVC_SUBJECT_H

#include <set>
#include <memory>

class Observer;

class Subject {
public:
       void subscribe( std::shared_ptr<Observer> );
       void unsubscribe( std::shared_ptr<Observer> );

protected:
       void notify();

private:
       typedef std::set< std::shared_ptr<Observer> > Observers;
       Observers observers_;
};

#endif

