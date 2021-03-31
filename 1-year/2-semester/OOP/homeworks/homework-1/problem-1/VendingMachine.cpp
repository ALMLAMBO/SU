#include "VendingMachine.hpp"

VendingMachine::VendingMachine() : size(0), capacity(1), income(0) {
	this->drinks = new Drink[this->capacity];
}

VendingMachine::VendingMachine(const VendingMachine& from) {
	this->copy_vending_machine(from);
}

VendingMachine::~VendingMachine() {
	delete[] this->drinks;
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
	if (this != &from) {
		delete[] this->drinks;
		this->copy_vending_machine(from);
	}

	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add) {
	if (this->index_of(to_add.get_name()) >= 0) {
		return false;
	}

	if (this->size == this->capacity) {
		this->drinks = this->resize();
	}

	this->drinks[this->size] = to_add;
	this->size++;

	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
	int result = -1;
	
	int index = this->index_of(drink_name);
	if (index >= 0) {
		if (money >= this->drinks[index].get_price()) {
			this->drinks[index] = Drink();
			result = 0;
		}
		else {
			result = 1;
		}

		this->income += money;
	}
	else {
		result = 2;
	}

	return result;
}

double VendingMachine::get_income() const {
	return this->income;
}

void VendingMachine::copy_vending_machine(const VendingMachine& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->income = other.income;
	this->drinks = this->copy_drinks(
		other.drinks, other.size, other.capacity);
}

Drink* VendingMachine::copy_drinks(const Drink* source, 
	int size, int capacity) {

	Drink* destination = new Drink[capacity];
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}

	for (int i = size; i < capacity; i++) {
		destination[i] = Drink();
	}

	return destination;
}

Drink* VendingMachine::resize() {
	this->capacity *= 2;
	Drink* new_drinks = nullptr;

	return this->copy_drinks(this->drinks, 
		this->size, this->capacity);
}

int VendingMachine::index_of(const char* name) const {
	int index = -1;

	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->drinks[i].get_name(), name) == 0) {
			index = i;
			break;
		}
	}

	return index;
}