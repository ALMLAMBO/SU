#include "Vehicle.hpp"

Vehicle::Vehicle(const std::string& maker,
	const std::string model, const std::string engine) {

	this->maker = maker;
	this->model = model;
	this->engine = engine;
}

std::string Vehicle::get_maker() const {
	return this->maker;
}

std::string Vehicle::get_model() const {
	return this->model;
}

std::string Vehicle::get_engine() const {
	return this->engine;
}