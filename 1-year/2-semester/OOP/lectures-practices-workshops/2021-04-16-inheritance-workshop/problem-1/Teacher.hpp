#pragma once
#ifndef __TEACHER_HPP__
#define __TEACHER_HPP__

#include "Person.hpp"

class Teacher : public Person {
public:
	Teacher(const std::string& first_name = "",
		const std::string& last_name = "", const unsigned int& age = 1,
		const std::string& town = "", const std::string& street = "",
		const unsigned int& experience = 0, const double& salary = 0, 
		const unsigned int& courses = 0);

	Teacher& set_experience(const unsigned int& new_experience);
	Teacher& set_salary(const double& new_salary);
	Teacher& set_courses(const unsigned int& new_courses);

	unsigned int get_experience() const;
	double get_salary() const;
	unsigned int get_courses() const;

private:
	unsigned int experience;
	double salary;
	unsigned int courses;
};

#endif // !__TEACHER_HPP__