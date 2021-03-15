#include "Vector.h"

using namespace std; 

Vector::Vector(Point a, Point b) {
	start = a;
	end = b;
}

void Vector::print() const {
	start.print();
	cout << " -> ";
	end.print();
}

double Vector::length() const {
	return start.distance(end);
}

void Vector::offset(double offset_x, double offset_y) {
	start.offset(offset_x, offset_y);
	end.offset(offset_x, offset_y);
}
