#pragma once
#ifndef __BACKPACK_HPP__
#define __BACKPACK_HPP__

#include <vector>
#include "Materials.hpp"
#include "Money.hpp"

template<typename T>
class Backpack {
public:
	Backpack();

	bool is_full() const;
	bool is_empty() const;
	Backpack<T>& clear();
	Backpack<T>& add(const T& item);
	Backpack<T>& remove();

	int get_slots() const;

private:
	std::vector<T> data;
	int slots;
};

#endif // !__BACKPACK_HPP__