#pragma once
#ifndef __MONEY_HPP__
#define __MONEY_HPP__

#include <utility>

class Money {
public:
	void add_silver(const unsigned int& silver);
	void add_gold(const unsigned int& gold);

	unsigned int get_gold() const;
	unsigned int get_silver() const;

private:
	std::pair<unsigned int, unsigned int> gold_and_silver;
};

#endif // !__MONEY_HPP__
