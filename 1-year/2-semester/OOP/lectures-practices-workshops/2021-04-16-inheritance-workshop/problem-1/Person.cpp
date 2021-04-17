#include "Person.hpp"

Person::Person(const std::string& first_name = "",
	const std::string& last_name = "", const unsigned int& age = 1,
	const std::string& town = "", const std::string& street = "") {

	this->first_name = first_name;
	this->last_name = last_name;
	this->age = age;
	this->town = town;
	this->street = street;
}

Person& Person::set_first_name(const std::string& new_first_name) {
	this->first_name = new_first_name;

	return *this;
}

Person& Person::set_last_name(const std::string& new_last_name) {
	this->last_name = new_last_name;

	return *this;
}

Person& Person::set_age(const unsigned int& new_age) {
	this->age = new_age;

	return *this;
}

Person& Person::set_town(const std::string& new_town) {
	this->town = new_town;

	return *this;
}

Person& Person::set_street(const std::string& new_street) {
	this->street = new_street;

	return *this;
}

std::string Person::get_first_name() const {
	return this->first_name;
}

std::string Person::get_last_name() const {
	return this->last_name;
}

unsigned int Person::get_age() const {
	return this->age;
}

std::string Person::get_town() const {
	return this->town;
}

std::string Person::get_street() const {
	return this->street;
}