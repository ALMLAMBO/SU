/*
* Point.cpp
*/

using namespace std;

#include "Point.h"

Point::Point(double init_x, double init_y) :
	x(init_x), y(init_y) { }

void Point::print() const {
	cout << '(' << x << ", " << y << ')';
}

double Point::distance(Point p) const {
	return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

void Point::offset(double offset_x, double offset_y)
{
	x += offset_x;
	y += offset_y;
}

