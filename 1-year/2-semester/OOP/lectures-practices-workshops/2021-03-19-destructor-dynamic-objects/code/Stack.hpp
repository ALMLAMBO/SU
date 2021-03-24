#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>

int const MAX = 100;

class Stack {
private:
	int* arr;
	int top;
	int size;

	bool full() const;
	void grow();

public:
	Stack();
	~Stack();
	bool empty() const;
	int peek() const;
	void push(int);
	int pop();
};

#endif /* __STACK_HPP__ */