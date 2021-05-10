#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(const int &min, const int &max) {
    this->min_value = min;
    this->max_value = max;
}

LimitedTwowayCounter::LimitedTwowayCounter(
        const int &min, const int &max, const int &initial) : Counter(initial) {

    this->min_value = min;
    this->max_value = max;
}

LimitedTwowayCounter::LimitedTwowayCounter(
        const int &min, const int &max,
        const int &initial, const unsigned int &step) :

       Counter(initial, step) {

    this->min_value = min;
    this->max_value = max;
}

int LimitedTwowayCounter::getMin() const {
    return this->min_value;
}

void LimitedTwowayCounter::decrement() {
    if((this->value - (int)this->step) >= this->min_value) {
        this->TwowayCounter::decrement();
    }
}