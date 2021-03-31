#include "drink.hpp"

Drink::Drink() {
	this->name = new char[1]{ '\0' };
	this->calories = 0;
	this->quantity = 0;
	this->price = 0;
}

Drink::Drink(const char* init_name, const int init_calories,
	const double& init_quantity, const double& init_price) {

	this->copy_char_array(this->name, init_name);
	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& other) {
	this->copy_drink(other);
}

Drink::~Drink() {
	delete[] this->name;
}

Drink& Drink::operator=(const Drink& other) {
	if (this != &other) {
		delete[] this->name;
		this->copy_drink(other);
	}

	return *this;
}

const char* Drink::get_name() const {
	return this->name;
}

int Drink::get_calories() const {
	return this->calories;
}

double Drink::get_quantity() const {
	return this->quantity;
}

double Drink::get_price() const {
	return this->price;
}

void Drink::set_name(const char* new_name) {
	delete[] this->name;
	this->copy_char_array(this->name, new_name);
}

void Drink::copy_char_array(char*& destination, const char* source) {
	int len = strlen(source);
	destination = new char[len + 1];
	strcpy(destination, source);
	destination[len] = '\0';
}

void Drink::copy_drink(const Drink& other) {
	this->copy_char_array(this->name, other.name);
	this->calories = other.calories;
	this->quantity = other.quantity;
	this->price = other.price;
}