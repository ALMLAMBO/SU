#pragma once
#ifndef __DYNAMIC_ARRAY_HPP__
#define __DYNAMIC_ARRAY_HPP__

#include <iostream>

class DynamicArray {
public:
	DynamicArray();
	DynamicArray(const DynamicArray& from);
	DynamicArray& operator=(const DynamicArray& from);
	~DynamicArray();

	void append(const int& item);
	int get(const int& index) const;
	int get_length() const;

	int operator[](const int index);
	void print_memory() const {
		for (int i = 0; i < this->capacity; i++) {
			std::cout << this->content[i] << " ";
		}
	}

private:
	int* content;
	int capacity;
	int length;
};

#endif // !__DYNAMIC_ARRAY_HPP__