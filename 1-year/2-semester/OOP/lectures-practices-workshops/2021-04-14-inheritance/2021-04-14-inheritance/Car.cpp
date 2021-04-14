#include "Car.hpp"

Car::Car() {
	this->seats = 0;
}

Car::Car(const std::string& maker, const std::string& model,
	const std::string& engine, const unsigned int& horsepower,
	const unsigned int& seats) : Vehicle(maker, model, engine, horsepower) {

	this->seats = seats;
}

unsigned int Car::get_seats() const {
	return this->seats;
}