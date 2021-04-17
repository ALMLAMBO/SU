#include "Teacher.hpp"

Teacher::Teacher(const std::string& first_name = "",
	const std::string& last_name = "", const unsigned int& age = 1,
	const std::string& town = "", const std::string& street = "",
	const unsigned int& experience = 0, const double& salary = 0,
	const unsigned int& courses = 0) : Person(first_name, last_name, age, town, street) {

	this->experience = experience;
	this->salary = std::abs(salary);
	this->courses = courses;
}

Teacher& Teacher::set_experience(const unsigned int& new_experience) {
	this->experience = new_experience;

	return *this;
}

Teacher& Teacher::set_salary(const double& new_salary) {
	this->salary = new_salary;

	return *this;
}

Teacher& Teacher::set_courses(const unsigned int& new_courses) {
	this->courses = new_courses;

	return *this;
}

unsigned int Teacher::get_experience() const {
	return this->experience;
}

double Teacher::get_salary() const {
	return this->salary;
}

unsigned int Teacher::get_courses() const {
	return this->courses;
}