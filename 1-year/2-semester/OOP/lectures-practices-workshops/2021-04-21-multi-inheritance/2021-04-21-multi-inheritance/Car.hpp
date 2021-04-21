#pragma once
#ifndef __CAR_HPP__
#define __CAR_HPP__

#include "Vehicle.hpp"

//virtual because of diamond problem
class Car : virtual public Vehicle {
public:
	Car(const std::string& maker = "", const std::string model = "",
		const std::string engine = "", bool is_self_driving = false);

	bool get_is_self_driving() const;

private:
	bool is_self_driving;
};

#endif // !__CAR_HPP__