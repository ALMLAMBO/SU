#include "Line.hpp"

Line::Line() : end(Point(2, 0)) { }

Line::Line(const Point& init_start, const Point& init_end) :
	start(init_start), end(init_end) { }

void Line::set_start(const Point& new_start) {
	this->start = new_start;
}

void Line::set_end(const Point& new_end) {
	this->end = new_end;
}

Point Line::get_start() const {
	return this->start;
}

Point Line::get_end() const {
	return this->end;
}

double Line::length() const {
	return this->start.distance_to(this->end);
}