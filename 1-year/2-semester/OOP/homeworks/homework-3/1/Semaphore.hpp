#ifndef __SEMAPHORE_HPP__
#define __SEMAPHORE_HPP__

#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter {
public:
    Semaphore();
    Semaphore(const bool& value);

    bool isAvailable() const;
    void wait();
    void signal();

private:
    int value;
    unsigned step;
};

#endif //__SEMAPHORE_HPP__