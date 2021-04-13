#pragma once
#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <iostream>
#include "Backpack.hpp"
#include "Equipment.hpp"

template<typename T>
class Inventory {
public:
	Inventory();

	/*friend std::ostream& operator<<(std::ostream& out, 
		const Inventory<T>& inventory);*/

	bool operator==(const Inventory<T>& other);
	bool operator!=(const Inventory<T>& other);

private:
	T data;
};

template<typename T>
Inventory<T>::Inventory() {
	this->data = T();
}

#endif // !__INVENTORY_HPP__