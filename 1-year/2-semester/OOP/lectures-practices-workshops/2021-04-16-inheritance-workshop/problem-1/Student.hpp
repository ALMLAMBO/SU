#pragma once
#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <unordered_set>
#include "Person.hpp"
#include "Course.hpp"

class Student : public Person {
public:
	Student(const std::string& first_name = "",
		const std::string& last_name = "", const unsigned int& age = 1,
		const std::string& town = "", const std::string& street = "",
		const unsigned int faculty_number = 0);

	Student& add_course(const Course& course);

	unsigned int get_faculty_number() const;
	double get_avg() const;

private:
	unsigned int faculty_number;
	std::unordered_set<Course> courses;
};

#endif // !__STUDENT_HPP__