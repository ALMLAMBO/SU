#include "Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter(0, 1, 0, 1) {}

Semaphore::Semaphore(const bool &value) :
    LimitedTwowayCounter(0, 1), step(1) {

    if(value) {
        this->value = 1;
    }
    else {
        this->value = 0;
    }
}

bool Semaphore::isAvailable() const {
    return this->value > 0;
}

void Semaphore::wait() {
    this->decrement();
}

void Semaphore::signal() {
    this->increment();
}