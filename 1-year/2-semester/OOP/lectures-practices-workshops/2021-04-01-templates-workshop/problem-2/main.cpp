#include <iostream>
#include "Stack.hpp"

using namespace std;

int main() {
	Stack<int> int_stack;
	int_stack.push(2);
	cout << int_stack.getSize() << endl;
	return 0;
}