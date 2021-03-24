#include <iostream>
#include "Stack.hpp"
#include "LinkedStack.hpp"

using namespace std;

int main() {
	Stack st;

	for (int i = 0; i < 1000; i++) {
		st.push(i);
	}

	while (!st.empty()) {
		cout << st.pop() << endl;
	}

	cout << endl;

	cout << "Number: ";
	int n;
	cin >> n;
	LinkedStack *lst = new LinkedStack;

	int x = n;
	while (x) {
		lst->push(x % 2);
		x /= 2;
	}

	while (!lst->empty()) {
		cout << lst->pop();
	}

	cout << endl;

	return 0;
}