#pragma once
#ifndef __EQUIPMENT_HPP__
#define __EQUIPMENT_HPP__
#include "Weapon.hpp"
#include "Armor.hpp"

template<typename T>
class Equipment {
public:
	Equipment();
	Equipment(const Equipment<T>& from);
	~Equipment();
	Equipment<T>& operator=(const Equipment<T>& from);
	
	bool is_empty() const;
	bool is_full() const;
	Equipment<T>& clear();
	Equipment<T>& add(const T& item);
	Equipment<T>& remove();
	double best_equipment() const;

	bool operator==(const Equipment<T>& from);
	bool operator!=(const Equipment<T>& from);

	int get_full_slots() const;
private:
	T* data;
	int size;
	unsigned int slots;

	void copy_equipment(const Equipment<T>& from);
	void clear_everything();
};

#endif // !__EQUIPMENT_HPP__