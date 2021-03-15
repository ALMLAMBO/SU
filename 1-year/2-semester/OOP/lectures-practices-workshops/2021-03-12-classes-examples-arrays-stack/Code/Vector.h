#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

#include "Point.h"

class Vector {
private:
	Point start;
	Point end;

public:
	Vector(Point, Point);
	
	Point get_start() const {
		return start;
	}

	Point get_end() const {
		return end;
	}

	void print() const;
	double length() const;

	void set_start(Point a) {
		start = a;
	}

	void set_end(Point b) {
		end = b;
	}

	void offset(double, double);
};

#endif // __VECTOR_H__