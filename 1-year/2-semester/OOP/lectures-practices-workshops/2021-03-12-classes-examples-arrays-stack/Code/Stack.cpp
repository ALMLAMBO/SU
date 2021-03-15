#include "Stack.h"

using namespace std;

int const MAX = 100;

Stack::Stack() : 
	arr(new int[100]), top(-1) { }

bool Stack::empty() const  {
	return top == -1;
}

int Stack::peek() const  {
	if (empty()) {
		cout << "Cannot get top element" << endl;
		return 0;
	}

	return arr[top];
}

void Stack::push(int x) {
	if (full()) {
		cout << "Stack if full" << endl;
	}
	else {
		arr[++top] = x;
	}
}

bool Stack::full() const {
	return top == MAX - 1;
}

int Stack::pop() {
	if (empty()) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	return arr[top--];
}