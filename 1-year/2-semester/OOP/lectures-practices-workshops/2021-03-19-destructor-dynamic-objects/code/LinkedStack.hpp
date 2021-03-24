#ifndef __LINKED_STACK_HPP__
#define __LINKED_STACK_HPP__

#include <iostream>

struct StackElement {
	int data;
	StackElement* next;
};

class LinkedStack {
private:
	StackElement* top;

public:
	LinkedStack();
	~LinkedStack();

	bool empty() const;
	int peek() const;
	void push(int);
	int pop();
};


#endif /* __LINKED_STACK_HPP__*/