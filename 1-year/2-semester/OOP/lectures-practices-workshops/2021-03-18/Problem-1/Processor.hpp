#pragma once
#ifndef __PROCESSOR_HPP__
#define __PROCESSOR_HPP__

#include <iostream>

class Processor {
public:
	Processor();
	Processor(const double init_frequency, const int init_cores, const int init_cache_size);

	void set_frequency(const double& new_frequency);
	void set_cores(const int& new_cores);
	void set_cache_size(const int& new_cache_size);

	double get_frequency() const;
	int get_cores() const;
	int get_cache_size() const;

	friend std::ostream& operator<<(std::ostream& out, const Processor& cpu);

private:
	double frequency;
	int cores;
	int cache_size;
};

#endif // !__PROCESSOR_HPP__
