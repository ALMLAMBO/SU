/*
* LinkedStack.cpp
*/

#include "LinkedStack.hpp"

LinkedStack::LinkedStack() {
	top = NULL;
}

LinkedStack::~LinkedStack() {
	std::cout << "Destructor" << std::endl;
	StackElement *toDelete;
	
	while (top != NULL) {
		toDelete = top;
		top = top->next;
		delete toDelete;
	}
}

bool LinkedStack::empty() const {
	return top == NULL;
}

int LinkedStack::peek() const {
	if (empty()) {
		std::cout << "Stack is empty\n";
		return 0;
	}

	return top->data;
}

void LinkedStack::push(int x) {
	StackElement* p = new StackElement;
	p->data = x;
	p->next = top;
	top = p;
}

int LinkedStack::pop() {
	if (empty()) {
		std::cout << "Stack is empty\n";
		return 0;
	}

	StackElement* p = top;
	top = top->next;
	int x = p->data;
	delete p;
	return x;
}