#include "Laptop.hpp"

Laptop::Laptop() {
	this->brand = new char[1]{ '\0' };
	this->model = new char[1]{ '\0' };
	this->price = 0.0f;
	this->display_size = 0.0f;
	this->battery_capacity = 0;
}

Laptop::Laptop(const char* brand, const char* model,
	const double price, const double display_size,
	const Processor& processor, const Ram& ram,
	const int battery_capacity) {

	this->brand = this->copy_char_array(brand);
	this->model = this->copy_char_array(model);
	this->price = price;
	this->display_size = display_size;
	this->processor = processor;
	this->ram = ram;
	this->battery_capacity = battery_capacity;
}

Laptop::Laptop(const Laptop& from) {
	this->brand = this->copy_char_array(from.brand);
	this->model = this->copy_char_array(from.model);
	this->price = from.price;
	this->display_size = from.display_size;
	this->processor = from.processor;
	this->ram = from.ram;
	this->battery_capacity = from.battery_capacity;
}

Laptop::~Laptop() {
	delete[] this->brand;
	delete[] this->model;
}

Laptop& Laptop::operator=(const Laptop& from) {
	if (this != &from) {
		delete[] this->brand;
		delete[] this->model;

		this->brand = this->copy_char_array(from.brand);
		this->model = this->copy_char_array(from.model);

		this->price = from.price;
		this->display_size = from.display_size;
		this->processor = from.processor;
		this->ram = from.ram;
		this->battery_capacity = from.battery_capacity;
	}

	return *this;
}

bool Laptop::operator>(const Laptop& other) {
	return this->display_size > other.display_size;
}

bool Laptop::operator<(const Laptop& other) {
	return !(*this > other);
}

bool Laptop::operator==(const Laptop& other) {
	return this->display_size == other.display_size;
}

bool Laptop::operator!=(const Laptop& other) {
	return !(*this == other);
}

void Laptop::upgrade_processor(const Processor& new_proceccor) {
	this->processor = new_proceccor;
}

void Laptop::upgrade_ram(const Ram& new_ram) {
	this->ram = new_ram;
}

std::ostream& operator<<(std::ostream& out, const Laptop& laptop) {
	std::cout << "Laptop:" << std::endl;
	std::cout << "brand -> " << laptop.brand
		<< "\nmodel-> " << laptop.model
		<< "\nprice -> " << laptop.price
		<< "\ndisplay size -> " << laptop.display_size 
		<< "\nprocessor -> " << laptop.processor 
		<< "ram -> " << laptop.ram 
		<< "battery -> " << laptop.battery_capacity
		<< std::endl;

	return out;
}

char* Laptop::copy_char_array(const char* source) {
	int len = strlen(source);
	char* destination = new char[len + 1];
	strcpy(destination, source);
	destination[len] = '\0';

	return destination;
}