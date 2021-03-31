#pragma once
#ifndef __DRINK_HPP__
#define __DRINK_HPP__
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

class Drink {
public:
	Drink();
	Drink(const char* init_name, const int init_calories, 
		const double& init_quantity, const double& init_price);
	
	Drink(const Drink&);
	~Drink();
	Drink& operator=(const Drink&);


	const char* get_name() const;
	int get_calories() const;
	double get_quantity() const;
	double get_price() const;

	void set_name(const char* new_name);

private:
	char* name;
	int calories;
	double quantity;
	double price;

	void copy_char_array(char*& destination, const char* source);
	void copy_drink(const Drink& other);

};

#endif // !__DRINK_HPP__
