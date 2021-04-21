#pragma once

#ifndef __TAXI_HPP__

#include "Car.hpp"
#include "Transport.hpp"

class Taxi : public Car, public Transport {
public:
	std::string to_string() const {
		std::string result;

		result += "Maker: " + this->maker + "\n";
		result += "Model: " + this->model + "\n";

		return result;
	}
};

#endif // !__TAXI_HPP__