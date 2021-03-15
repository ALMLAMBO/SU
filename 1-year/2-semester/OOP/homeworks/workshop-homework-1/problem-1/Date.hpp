#pragma once
#ifndef __DATE_HPP__
#define __DATE_HPP__

class Date {
public:
	Date(int day, int month, int year);

	Date add_days(const int& days);
	Date remove_days(const int& days);
	bool is_leap_year() const;
	int days_to_xmas() const;
	int days_to_end_of_year() const;
	int days_to(const Date& other) const;
	bool is_later_than(const Date& other) const;

private:
	int day_, month_, year_;
};

#endif // !__DATE_HPP__