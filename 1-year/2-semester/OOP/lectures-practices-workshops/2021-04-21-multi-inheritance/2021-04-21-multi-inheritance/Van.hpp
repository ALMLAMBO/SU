#pragma once
#ifndef __VAN_HPP__
#define __VAN_HPP__

#include "Vehicle.hpp"

class Van : public Vehicle {
public:
	Van(const std::string& maker = "", const std::string model = "",
		const std::string engine = "", const int& seats = 0);

	int get_seats() const;

private:
	int seats;
};

#endif // !__VAN_HPP__
