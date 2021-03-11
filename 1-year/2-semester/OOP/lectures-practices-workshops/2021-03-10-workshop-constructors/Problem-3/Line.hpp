#pragma once
#ifndef __LINE_HPP__
#define __LINE_HPP__

#include "Point.hpp"

class Line {
public:
	Line();
	Line(const Point& init_start, const Point& init_end);

	void set_start(const Point& new_start);
	void set_end(const Point& new_end);

	Point get_start() const;
	Point get_end() const;

	double length() const;

private:
	Point start;
	Point end;
};

#endif // !__LINE_HPP__