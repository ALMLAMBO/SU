#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

using namespace std;

int main() {
	Point p1(1, 2), p2(4, 8);
	cout << p1.distance_to(p2) << endl;

	Line line1(p1, p2);
	cout << line1.length() << endl;

	Line line2;
	cout << line2.length() << endl;

	return 0;
}