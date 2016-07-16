#ifndef OBSERVER_H
#define OBSERVER_H

template <typename NotificationContext>
class Observer {
public:
	virtual void update(NotificationContext context) = 0;
};

#endif
