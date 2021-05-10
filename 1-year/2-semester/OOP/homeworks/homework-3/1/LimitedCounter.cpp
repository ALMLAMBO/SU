#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(const int &max) :
    max_value(max), Counter() {}

LimitedCounter::LimitedCounter(const int &max, const int &initial) : Counter(initial) {
    this->max_value = max;
}

LimitedCounter::LimitedCounter(const int &max, const int &initial,
                               const unsigned int &step) : Counter(initial, step) {

    this->max_value = max;
}

int LimitedCounter::getMax() const {
    return this->max_value;
}

void LimitedCounter::increment() {
    if((this->value + (int)this->step) <= this->max_value) {
        this->Counter::increment();
    }
}