#include "Vehicle.hpp"

Vehicle::Vehicle() {
	this->maker = "";
	this->model = "";
	this->engine = "";
	this->horsepower = 0;
}

Vehicle::Vehicle(const std::string& maker, const std::string& model,
	const std::string& engine, const unsigned int& horsepower) {

	this->maker = maker;
	this->model = model;
	this->engine = engine;
	this->horsepower = horsepower;
}

std::string Vehicle::get_maker() const {
	return this->maker;
}

std::string Vehicle::get_model() const {
	return this->model;
}

std::string Vehicle::get_engine() const {
	return this->maker;
}

unsigned int Vehicle::get_horsepower() const {
	return this->horsepower;
}