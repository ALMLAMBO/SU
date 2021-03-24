/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*/
#pragma once
#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>

class Date {
public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);

	void add_days(const int& days);
	void remove_days(const int& days);
	bool is_leap_year() const;
	int days_to_xmas();
	int days_to_end_of_year();
	int days_to(const Date& other);
	bool is_later_than(const Date& other) const;
	void print() const;

private:
	unsigned int day_, month_, year_;
	bool valid;
	int get_days_per_month(int month) const;
	int days_to_begin_of_next_month() const;
};

#endif // !__DATE_HPP__