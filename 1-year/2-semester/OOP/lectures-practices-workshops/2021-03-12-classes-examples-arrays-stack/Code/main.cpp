#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Stack.h"

using namespace std;

int main() {
	Point p;

	p.set_x(1.0);
	p.set_y(-2.0);
	p.print();

	cout << endl;

	Point q(2, 3);
	cout << "Distance " << p.distance(q) << endl;

	Point arr[2];
	for (int i = 0; i < 2; i++) {
		arr[i].set_x(i + 2);
		arr[i].set_y(i + 1);

		arr[i].print();
		cout << endl;
	}

	Vector v(Point(0, 0), Point(2, 2));

	v.print();
	cout << endl;

	v.offset(2, 2);
	v.print();

	cout << endl;
	cout << "Length: " << v.length() << endl;

	Stack s;
	for (int i = 0; i < 10; i++) {
		s.push(i * 2);
	}

	cout << s.peek() << endl;
	cout << s.empty() << endl;

	for (int i = 0; i < 10; i++) {
		cout << s.pop() << endl;
	}

	cout << s.pop() << endl;
	cout << s.empty() << endl;

	return 0;
}