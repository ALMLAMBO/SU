#include "Date.hpp"

Date::Date(const int day = 1,
	const int month = 1, const int year = 2000) {

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