#include "Student.hpp"

Student::Student(const std::string& first_name = "",
	const std::string& last_name = "", const unsigned int& age = 1,
	const std::string& town = "", const std::string& street = "",
	const unsigned int faculty_number = 0) : 
		Person(first_name, last_name, age, town, street) { }

Student& Student::add_course(const Course& course) {
	this->courses.insert(course);

	return *this;
}

unsigned int Student::get_faculty_number() const {
	return this->faculty_number;
}

double Student::get_avg() const {
	double avg = 0;
	
	std::unordered_set<Course>::const_iterator it;
	for (it = this->courses.cbegin(); it != this->courses.cend(); it++) {
		avg += it.operator*().get_grade();
	}

	return avg / this->courses.size();
}