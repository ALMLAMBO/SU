#include "Van.hpp"

Van::Van(const std::string& maker, const std::string model,
	const std::string engine, const int& seats) : 
	
	Vehicle(maker, model, engine) {

	this->seats = seats;
}

int Van::get_seats() const {
	return this->seats;
}