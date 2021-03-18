#include "Processor.hpp"


Processor::Processor() : 
	frequency(0), cores(0), cache_size(0) { }

Processor::Processor(const double init_frequency,
	const int init_cores, const int init_cache_size) {

	this->frequency = init_frequency;
	this->cores = init_cores;
	this->cache_size = init_cache_size;
}

void Processor::set_frequency(const double& new_frequency) {
	this->frequency = new_frequency;
}

void Processor::set_cores(const int& new_cores) {
	this->cores = new_cores;
}

void Processor::set_cache_size(const int& new_cache_size) {
	this->cache_size = new_cache_size;
}

double Processor::get_frequency() const {
	return this->frequency;
}

int	Processor::get_cores() const {
	return this->cores;
}

int Processor::get_cache_size() const {
	return this->cache_size;
}

std::ostream& operator<<(std::ostream& out, const Processor& cpu) {
	std::cout << "Processor(" << cpu.frequency
		<< ", " << cpu.cores
		<< cpu.cache_size << ")" << std::endl;
	
	return out;
}