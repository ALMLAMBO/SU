/*
* Point.h
*/

#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include <cmath>

class Point {
private:
	double x, y;

public:
	Point() {
		x = y = 0;
	};

	Point(double init_x, double inti_y);

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}

	void print() const;
	double distance(Point) const;
	
	void set_x(double new_x) {
		this->x = new_x;
	}
	void set_y(double new_y) {
		this->y = y;
	}
	
	void offset(double offset_x, double offset_y);
};

#endif // __POINT_H__