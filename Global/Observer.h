#ifndef OBSERVER_H
#define OBSERVER_H

template <typename NotificationContext>
class Observer {
public:
    // Handle updates from the Model
	virtual void update(NotificationContext context) = 0;
};

#endif
