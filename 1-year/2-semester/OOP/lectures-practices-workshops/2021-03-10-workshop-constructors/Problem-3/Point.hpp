#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <cmath>

class Point {
public:
	Point();
	Point(const int init_x, const int init_y);

	void set_x(const int x);
	void set_y(const int y);

	int get_x() const;
	int get_y() const;

	double distance_to(const Point& to) const;

private:
	int x;
	int y;
};

#endif // !__POINT_HPP__