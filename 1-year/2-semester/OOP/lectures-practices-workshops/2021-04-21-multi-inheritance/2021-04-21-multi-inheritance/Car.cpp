#include "Car.hpp"

Car::Car(const std::string& maker, const std::string model,
	const std::string engine, bool is_self_driving) : 
	
	Vehicle(maker, model, engine) {

	this->is_self_driving = is_self_driving;
}

bool Car::get_is_self_driving() const {
	return this->is_self_driving;
}