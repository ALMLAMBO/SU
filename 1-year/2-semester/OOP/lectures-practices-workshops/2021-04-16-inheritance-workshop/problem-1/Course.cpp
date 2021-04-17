#include "Course.hpp"

Course::Course(const std::string name = "",
	const Teacher& teacher = Teacher(),
	const double& grade = 0.0) {

	this->name = name;
	this->teacher = teacher;
	this->grade = grade;
}

Course& Course::set_name(const std::string& new_name) {
	this->name = new_name;

	return *this;
}

Course& Course::set_teacher(const Teacher& new_teacher) {
	this->teacher = new_teacher;

	return *this;
}

Course& Course::set_grade(const double& new_grade) {
	this->grade = new_grade;

	return *this;
}

std::string Course::get_name() const {
	return this->name;
}

Teacher Course::get_teacher() const {
	return this->teacher;
}

double Course::get_grade() const {
	return this->grade;
}