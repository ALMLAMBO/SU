#pragma once
#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include "Teacher.hpp"

class Course {
public:
	Course(const std::string name = "",
		const Teacher& teacher = Teacher(),
		const double& grade = 0.0);

	Course& set_name(const std::string& new_name);
	Course& set_teacher(const Teacher& new_teacher);
	Course& set_grade(const double& new_grade);

	std::string get_name() const;
	Teacher get_teacher() const;
	double get_grade() const;

private:
	std::string name;
	Teacher teacher;
	double grade;
};

#endif // !__COURSE_HPP__