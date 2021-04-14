#pragma once
#ifndef __CAR_HPP__
#define __CAR_HPP__

#include "Vehicle.hpp"

class Car : public Vehicle {
public:
	Car();
	Car(const std::string& maker, const std::string& model,
		const std::string& engine, const unsigned int& horsepower,
		const unsigned int& seats);

	unsigned int get_seats() const;

private:
	unsigned int seats;
};

#endif // !__CAR_HPP__