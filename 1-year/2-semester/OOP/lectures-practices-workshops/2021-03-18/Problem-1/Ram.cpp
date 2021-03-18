#include "Ram.hpp"

Ram::Ram() : frequency(0), size(0) {};

Ram::Ram(const int init_frequency, const int init_size) : 
	frequency(init_frequency), size(init_size) { }

void Ram::set_frequency(const int& new_frequency) {
	this->frequency = new_frequency;
}

void Ram::set_size(const int& new_size) {
	this->size = new_size;
}

int Ram::get_frequency() const {
	return this->frequency;
}

int Ram::get_size() const {
	return this->size;
}

std::ostream& operator<<(std::ostream& out, const Ram& ram) {
	std::cout << "Ram(" << ram.frequency << ", "
		<< ram.size << ")" << std::endl;
	
	return out;
}