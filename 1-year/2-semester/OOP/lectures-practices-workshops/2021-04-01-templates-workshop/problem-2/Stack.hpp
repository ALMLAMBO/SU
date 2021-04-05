#pragma once
#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <vector>

template<typename T>
class Stack {
public:
	void push(T element);
	T pop();
	int getSize() const;

private:
	std::vector<T> elements;
};

template<typename T>
void Stack<T>::push(T element) {
	this->elements.push_back(element);
}

template<typename T>
T Stack<T>::pop() {
	return this->elements.pop_back();
}

template<typename T>
int Stack<T>::getSize() const {
	return this->elements.size();
}
#endif // !__STACK_HPP__