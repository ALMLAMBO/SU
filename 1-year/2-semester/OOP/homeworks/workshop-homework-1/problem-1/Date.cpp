#include "Date.hpp"

Date::Date() : day_(1), 
	month_(1), year_(2000) { }

Date::Date(const unsigned int day,
	const unsigned int month, const unsigned int year) {

	this->day_ = day;
	this->month_ = month;
	this->year_ = year;
}

Date Date::add_days(const int& days) {
	return Date();
}

Date Date::remove_days(const int& days) {
	return Date();
}

bool Date::is_leap_year() const {
	if (this->year_ % 400 == 0) {
		return true;
	}
	else if (this->year_ % 100 == 0) {
		return false;
	}
	else if (this->year_ % 4 == 0) {
		return true;
	}

	return false;
}

int Date::days_to_xmas() const {
	return 0;
}

int Date::days_to_end_of_year() const {
	return 0;
}

int Date::days_to(const Date& other) const {
	return 0;
}

bool Date::is_later_than(const Date& other) const {
	return false;
}