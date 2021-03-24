#include "Stack.hpp"

using namespace std;

Stack::Stack() {
	size = MAX;
	arr = new int[size];
	top = -1;
}

void Stack::grow() {
	int *newArr = new int[2 * size];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size *= 2;
}

Stack::~Stack() {
	delete[] arr;
}

bool Stack::empty() const {
	return top == -1;
}

int Stack::peek() const {
	if (empty()) {
		cout << "Stack is empty\n";
		return 0;
	}

	return arr[top];
}

void Stack::push(int x) {
	if (full()) {
		grow();
	}
	arr[++top] = x;
}

bool Stack::full() const {
	return top == size - 1;
}

int Stack::pop() {
	if (empty()) {
		cout << "Stack is empty!\n";
		return 0;
	}
	return arr[top--];
}
