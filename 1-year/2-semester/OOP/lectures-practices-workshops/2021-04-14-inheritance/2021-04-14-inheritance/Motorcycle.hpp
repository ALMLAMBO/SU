#pragma once
#ifndef __MOTORCYCLE_HPP__
#define __MOTORCYCLE_HPP__

#include "Vehicle.hpp"

class Motorcycle : public Vehicle {
public:
	Motorcycle();
	Motorcycle(const std::string& maker, const std::string& model,
		const std::string& engine, const unsigned int& horsepower,
		const unsigned int& seats);

	unsigned int get_luggage() const;

private:
	unsigned int luggage;
};

#endif // !__MOTORCYCLE_HPP__
