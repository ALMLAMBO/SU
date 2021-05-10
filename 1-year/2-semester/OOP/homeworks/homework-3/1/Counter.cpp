#include "Counter.hpp"

Counter::Counter() : value(0), step(1) {}

Counter::Counter(const int &initial) :
    value(initial), step(1) {}

Counter::Counter(const int &initial, const unsigned int &step) {
    this->value = initial;
    this->step = step;
}

void Counter::increment() {
    this->value += this->step;
}

int Counter::getTotal() const {
    return this->value;
}

unsigned Counter::getStep() const {
    return this->step;
}