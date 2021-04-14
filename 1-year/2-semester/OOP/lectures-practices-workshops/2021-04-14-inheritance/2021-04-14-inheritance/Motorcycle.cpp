#include "Motorcycle.hpp"

Motorcycle::Motorcycle() : luggage(0) {}

Motorcycle::Motorcycle(const std::string& maker, const std::string& model,
	const std::string& engine, const unsigned int& horsepower,
	const unsigned int& seats) : Vehicle(maker, model, engine, horsepower) {

	this->luggage = luggage;
}

unsigned int Motorcycle::get_luggage() const {
	return this->luggage;
}