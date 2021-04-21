#pragma once
#ifndef __ROUTE_HPP__
#define __ROUTE_HPP__

#include <string>

class Route {
public:
	Route(const std::string& start = "", const std::string& end = "");

	std::string get_start() const;
	std::string get_end() const;

private:
	std::string start;
	std::string end;
};

#endif // !__ROUTE_HPP__