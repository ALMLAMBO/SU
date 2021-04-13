#include "Money.hpp"

void Money::add_silver(const unsigned int& silver) {
	this->gold_and_silver.second += silver;

	if (this->gold_and_silver.second >= 100) {
		this->gold_and_silver.second -= 100;
		this->gold_and_silver.first++;
	}
}

void Money::add_gold(const unsigned int& gold) {
	this->gold_and_silver.first += gold;
}

unsigned int Money::get_gold() const {
	return this->gold_and_silver.first;
}

unsigned int Money::get_silver() const {
	return this->gold_and_silver.second;
}