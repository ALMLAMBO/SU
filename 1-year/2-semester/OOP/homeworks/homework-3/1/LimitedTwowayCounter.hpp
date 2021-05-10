#ifndef __LIMITED_TWO_WAY_COUNTER_HPP__
#define __LIMITED_TWO_WAY_COUNTER_HPP__

#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter {
public:
    LimitedTwowayCounter() = default;
    LimitedTwowayCounter(const int& min, const int& max);
    LimitedTwowayCounter(const int& min, const int& max, const int& initial);
    LimitedTwowayCounter(const int& min, const int& max,
                         const int& initial, const unsigned& step);

    int getMin() const;
    void decrement() override;

private:
    int min_value;
};


#endif //__LIMITED_TWO_WAY_COUNTER_HPP__
