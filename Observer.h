#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>

template <typename T>
class Observer {
private:
    T value;
    std::function<void(const T)> * updateCallback;
public:
    Observer();
    explicit Observer(std::function<void(const T)> * initialCallback);
    ~Observer();
    T getValue() const;
    void update(T newValue);
    void setCallback(std::function<void(const T)> * newCallback);
};
#include "Observer.cpp"
#endif