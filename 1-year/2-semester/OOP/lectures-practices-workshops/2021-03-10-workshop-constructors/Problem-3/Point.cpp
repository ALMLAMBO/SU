#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const int init_x, const int init_y) : 
	x(init_x), y(init_y) { }

void Point::set_x(const int new_x) {
	this->x = new_x;
}

void Point::set_y(const int new_y) {
	this->y = new_y;
}

int Point::get_x() const {
	return this->x;
}

int Point::get_y() const {
	return this->y;
}

double Point::distance_to(const Point& to) const {
	return sqrt(pow(to.x - this->x, 2) + 
		pow(to.y - this->y, 2));
}