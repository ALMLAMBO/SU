#pragma once
#ifndef __LAPTOP_HPP__
#define __LAPTOP_HPP__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Processor.hpp"
#include "Ram.hpp"

class Laptop {
public:
	Laptop();
	Laptop(const char* brand, const char* model, 
		const double price, const double display_size, 
		const Processor& processor, const Ram& ram,
		const int battery_capacity);

	Laptop(const Laptop& from);
	~Laptop();
	Laptop& operator=(const Laptop& from);

	bool operator>(const Laptop& other);
	bool operator<(const Laptop& other);
	bool operator==(const Laptop& other);
	bool operator!=(const Laptop& other);

	void upgrade_processor(const Processor& new_proceccor);
	void upgrade_ram(const Ram& new_ram);

	friend std::ostream& operator<<(std::ostream& out, const Laptop& laptop);
private:
	char* brand;
	char* model;
	double price;
	double display_size;
	Processor processor;
	Ram ram;
	int battery_capacity;

	char* copy_char_array(const char* source);
};

#endif // !__LAPTOP_HPP__