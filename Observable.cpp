#ifndef OBSERVABLE_CPP
#define OBSERVABLE_CPP

#include "Observable.h"

template <typename T>
Observable<T>::Observable(T initialValue) {
    this->value = initialValue;
}

template <typename T>
Observable<T>::~Observable() {
    this->subscribers.clear();
}

template <typename T>
void Observable<T>::subscribe(Observer<T> * newSubscriber) {
    this->subscribers.insert(newSubscriber);
    newSubscriber->update(this->value);
}

template <typename T>
void Observable<T>::unsubscribe(Observer<T> * subscriber) {
    this->subscribers.erase(subscriber);
}

template <typename T>
void Observable<T>::update(T newValue) {
    this->value = newValue;
    for (Observer<T> * subscriber : this->subscribers) {
        subscriber->update(this->value);
    }
}
#endif