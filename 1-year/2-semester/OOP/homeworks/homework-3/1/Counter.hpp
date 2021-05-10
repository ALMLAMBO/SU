#ifndef __COUNTER_HPP__
#define __COUNTER_HPP__

class Counter {
public:
    Counter();
    Counter(const int& initial);
    Counter(const int& initial, const unsigned& step);

    virtual void increment();
    int getTotal() const;
    unsigned getStep() const;

protected:
    int value;
    unsigned step;
};


#endif //__COUNTER_HPP__
