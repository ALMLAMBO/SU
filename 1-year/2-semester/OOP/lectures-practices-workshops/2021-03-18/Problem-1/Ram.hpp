#pragma once
#ifndef __RAM_HPP__
#define __RAM_HPP__

#include <iostream>

class Ram {
public:
	Ram();
	Ram(const int init_frequency, const int init_size);

	void set_frequency(const int& new_frequency);
	void set_size(const int& new_size);

	int get_frequency() const;
	int get_size() const;

	friend std::ostream& operator<<(std::ostream& out, const Ram& ram);
private:
	int frequency;
	int size;
};

#endif // !__RAM_HPP__
