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
#include "Date.hpp"

Date::Date() : day_(1), 
	month_(1), year_(2000), valid(true) { }

Date::Date(const unsigned int day,
	const unsigned int month, const unsigned int year) : valid(true) {

	if (month > 12) {
		std::cout << "Invalid month" << std::endl;
		this->valid = false;
	}

	if (year < 1) {
		std::cout << "Invalid date" << std::endl;
	}

	if ((month == 1 || month == 3 || month == 5
		|| month == 7 || month == 8 || month == 10
		|| month == 12) && day > 31) {

		std::cout << "Invalid date" << std::endl;
		this->valid = false;
	}

	if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& day > 30) {

		std::cout << "Invalid date" << std::endl;
		this->valid = false;
	}

	if (month == 2) {
		if (year % 400 == 0 && day > 29) {
			std::cout << "Invalid date" << std::endl;
			this->valid = false;
		}
		else if (year % 100 == 0 && day > 28) {
			std::cout << "Invalid date" << std::endl;
			this->valid = false;
		}
		else if (year % 4 == 0 && day > 29) {
			std::cout << "Invalid date" << std::endl;
			this->valid = false;
		}
		else if (day > 28) {
			std::cout << "Invalid date" << std::endl;
			this->valid = false;
		}
	}

	this->day_ = day;
	this->month_ = month;
	this->year_ = year;
}

void Date::add_days(const int& days) {
	if (this->valid) {
		int all_days_to_add = days;

		int days_month = this->get_days_per_month(this->month_);
		if (this->day_ + days < days_month) {
			this->day_ += days;
			return;
		}

		//change name
		int days_to_end_month = this->days_to_begin_of_next_month();
		all_days_to_add -= days_to_end_month;
		this->day_ += days_to_end_month;

		days_to_end_month = 0;
		int days_next_month = 0;

		while (all_days_to_add > days_next_month) {
			this->month_++;
			if (this->month_ > 12) {
				this->month_ = 1;
				this->year_++;
			}

			days_next_month = this->get_days_per_month(this->month_);
			all_days_to_add -= days_next_month;
			this->day_ = days_next_month;
		}

		this->month_++;
		this->day_ = all_days_to_add;
	}
}

void Date::remove_days(const int& days) {
	if (this->valid) {
		int all_days_to_remove = days;
		if (this->day_ > days) {
			this->day_ -= days;
			return;
		}

		//change name
		all_days_to_remove -= this->day_;
		
		int days_next_month = 0;
		this->day_ = 1;
		this->month_--;

		while (all_days_to_remove > days_next_month) {
			if (this->month_ == 0) {
				this->month_ = 12;
				this->year_--;
			}
			
			days_next_month = this->get_days_per_month(this->month_);
			all_days_to_remove -= days_next_month;
			this->day_ = 1;
			this->month_--;
		}

		if (this->month_ == 0) {
			this->month_ = 12;
			this->year_--;
		}

		days_next_month = this->get_days_per_month(this->month_);

		this->day_ = days_next_month - all_days_to_remove;
	}
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

int Date::days_to_xmas() {
	Date xmas(25, 12, this->year_);
	int result = this->days_to(xmas);

	return result;
}

int Date::days_to_end_of_year() {
	Date new_year(1, 1, this->year_ + 1);
	
	return this->days_to(new_year);
}

int Date::days_to(const Date& other) {
	int result = 0;

	if (this->year_ == other.year_) {
		result = this->days_to_begin_of_next_month();
		this->month_++;
		
		while (this->month_ != other.month_) {
			result += this->get_days_per_month(this->month_);
			this->month_++;
		}

		result += other.day_;
	}
	else {
		Date begin(1, 1, this->year_);
		Date begin_other(1, 1, other.year_);
		int days_to_remove = 0;

		while (begin.month_ != this->month_) {
			days_to_remove += begin.get_days_per_month(begin.month_);
			begin.month_++;
		}

		days_to_remove += this->day_;

		while (begin_other.month_ != other.month_) {
			result += begin.get_days_per_month(other.month_);
			begin_other.month_++;
		}

		result += other.day_;

		for (int year = this->year_; year < other.year_; year++) {
			if (this->year_ % 400 == 0) {
				result += 366;
			}
			else if (this->year_ % 100 == 0) {
				result += 365;
			}
			else if (this->year_ % 4 == 0) {
				result += 366;
			}
			else {
				result += 365;
			}
		}

		result -= days_to_remove + 1;
	}

	return result;
}

bool Date::is_later_than(const Date& other) const {
	if (this->year_ > other.year_) {
		return false;
	}
	else if(this->year_ < other.year_) {
		return true;
	}
	else {
		if (this->month_ > other.month_) {
			return false;
		}
		else if (this->month_ < other.month_) {
			return true;
		}
		else {
			if (this->day_ >= other.day_) {
				return false;
			}
			else if (this->day_ < other.day_) {
				return true;
			}
		}
	}
}

void Date::print() const {
	std::cout << "Date -> ";
	
	if (this->day_ < 10) {
		std::cout << "0";
	}

	std::cout << this->day_ << ".";

	if (this->month_ < 10) {
		std::cout << "0";
	}

	std::cout << this->month_ << ".";
	std::cout << this->year_ << std::endl;
}

int Date::get_days_per_month(int month) const {
	int days = 0;
	
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10: 
		case 12: days = 31; break;
		case 4: 
		case 6: 
		case 9: 
		case 11: days = 30; break;
		case 2: {
			if (this->is_leap_year()) {
				days = 29;
			}
			else {
				days = 28;
			}
		} break;
	}

	return days;
}

int Date::days_to_begin_of_next_month() const {
	int days_in_month = this->get_days_per_month(this->month_);

	return days_in_month - this->day_;
}