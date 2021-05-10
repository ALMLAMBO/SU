#ifndef __LIMITED_COUNTER_HPP__
#define __LIMITED_COUNTER_HPP__

#include "Counter.hpp"

class LimitedCounter : virtual public Counter {
public:
    LimitedCounter() = default;
    LimitedCounter(const int& max);
    LimitedCounter(const int& max, const int& initial);
    LimitedCounter(const int& max, const int& initial, const unsigned& step);

    int getMax() const;
    void increment() override;

protected:
    int max_value;
};

#endif //__LIMITED_COUNTER_HPP__
