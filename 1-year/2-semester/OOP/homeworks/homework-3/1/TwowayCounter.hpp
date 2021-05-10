#ifndef __TWO_WAY_COUNTER_HPP__
#define __TWO_WAY_COUNTER_HPP__

#include "Counter.hpp"

class TwowayCounter : virtual public Counter {
public:
    TwowayCounter();
    TwowayCounter(const int& initial);
    TwowayCounter(const int& initial, const unsigned& step);

    virtual void decrement();
};

#endif //__TWO_WAY_COUNTER_HPP__