#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>

#include "Observer.h"

template <typename T>
class Observable {
private:
    T value;
    std::set<Observer<T> *> subscribers;
public:
    Observable() = delete;
    explicit Observable(T initialValue);
    ~Observable();
    void subscribe(Observer<T> * newSubscriber);
    void unsubscribe(Observer<T> * subscriber);
    void update(T newValue);
};
#include "Observable.cpp"
#endif