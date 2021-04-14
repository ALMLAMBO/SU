#pragma once
#ifndef __VEHICLE_HPP__
#define __VEHICLE_HPP__

#include <string>

class Vehicle {
public:
	Vehicle();
	Vehicle(const std::string& maker, const std::string& model, 
		const std::string& engine, const unsigned int& horsepower);

	std::string get_maker() const;
	std::string get_model() const;
	std::string get_engine() const;
	unsigned int get_horsepower() const;

private:
	std::string maker;
	std::string model;
	std::string engine;
	unsigned int horsepower;
};

#endif // !__VEHICLE_HPP__