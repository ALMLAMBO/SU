#pragma once
#ifndef __VENDING_MACHINE_HPP__
#define __VENDING_MACHINE_HPP__

#include "drink.hpp"

class VendingMachine {
public:
	VendingMachine();
	VendingMachine(const VendingMachine& from);
	~VendingMachine();
	VendingMachine& operator=(const VendingMachine& from);

	bool add_drink(const Drink& to_add);
	int buy_drink(const char* drink_name, const double money);

	double get_income() const;

private:
	double income;
	Drink* drinks;
	int size;
	int capacity;

	void copy_vending_machine(const VendingMachine& other);
	Drink* copy_drinks(const Drink* source, int size, int capacity);
	Drink* resize();
	int index_of(const char* name) const;
};

#endif // !__VENDING_MACHINE_HPP__