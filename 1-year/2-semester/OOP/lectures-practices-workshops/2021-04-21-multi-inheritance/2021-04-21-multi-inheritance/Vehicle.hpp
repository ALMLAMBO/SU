#pragma once
#ifndef __VEHICLE_HPP__
#define __VEHICLE_HPP__

#include <string>

class Vehicle {
public:
	Vehicle(const std::string& maker = "", 
		const std::string model = "", const std::string engine = "");

	std::string get_maker() const;
	std::string get_model() const;
	std::string get_engine() const;

protected:
	std::string maker;
	std::string model;
	std::string engine;
};

#endif // !__VEHICLE_HPP__