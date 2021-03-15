#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

class Stack {
private:
	int* arr;
	int top;

	bool full() const;

public:
	Stack();

	bool empty() const;
	int peek() const;
	void push(int);
	int pop();
};

#endif /* __STACK_H__ */