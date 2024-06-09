#ifndef OBSERVER_CPP
#define OBSERVER_CPP

#include "Observer.h"

template <typename T>
Observer<T>::Observer() {
    this->updateCallback = nullptr;
}

template <typename T>
Observer<T>::Observer(std::function<void(T)> * initialCallback) {
    this->updateCallback = initialCallback;
}

template <typename T>
Observer<T>::~Observer() {
    this->updateCallback = nullptr;
}

template <typename T>
T Observer<T>::getValue() const {
    return this->value;
}

template <typename T>
void Observer<T>::update(T newValue) {
    this->value = newValue;
    if (this->updateCallback != nullptr) {
        (*this->updateCallback)(this->value);
    }
}

template <typename T>
void Observer<T>::setCallback(std::function<void(T)> * newCallback) {
    this->updateCallback = newCallback;
}
#endif