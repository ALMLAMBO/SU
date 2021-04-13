#include "Equipment.hpp"

template<>
Equipment<Armor>::Equipment() : size(0), slots(24) {
	this->data = new Armor[this->slots];
}

template<>
Equipment<Weapon>::Equipment() : size(0), slots(24) {
	this->data = new Weapon[this->slots];
}

template<typename T>
Equipment<T>::Equipment(const Equipment<T>& from) {
	this->copy_equipment(from);
}

template<>
Equipment<Armor>::~Equipment() {
	this->clear_everything();
}

template<>
Equipment<Weapon>::~Equipment() {
	this->clear_everything();
}

template<>
Equipment<Armor>& Equipment<Armor>::operator=(const Equipment<Armor>& from) {
	if (this != &from) {
		delete[] this->data;
		this->copy_equipment(from);
	}

	return *this;
}

template<>
Equipment<Weapon>& Equipment<Weapon>::operator=(const Equipment<Weapon>& from) {
	if (this != &from) {
		delete[] this->data;
		this->copy_equipment(from);
	}

	return *this;
}

template<typename T>
bool Equipment<T>::is_empty() const {
	return this->slots == 24;
}

template<typename T>
bool Equipment<T>::is_full() const {
	return this->slots == 0;
}

template<typename T>
Equipment<T>& Equipment<T>::clear() {
	this->clear_everything();

	return *this;
}

template<>
Equipment<Armor>& Equipment<Armor>::add(const Armor& armor) {
	if (!this->is_full()) {
		this->data[this->size] = armor;
		this->size++;
		this->slots--;
	}

	return *this;
}

template<>
Equipment<Weapon>& Equipment<Weapon>::add(const Weapon& weapon) {
	if (!this->is_full()) {
		this->data[this->size] = weapon;
		this->size++;
		this->slots -= weapon.get_slots();
	}

	return *this;
}

template<>
Equipment<Armor>& Equipment<Armor>::remove() {
	if (this->is_empty()) {
		this->data[this->size] = Armor();
		this->size--;
		this->slots++;
	}

	return *this;
}

template<>
Equipment<Weapon>& Equipment<Weapon>::remove() {
	if (this->is_empty()) {
		int weapon_slots = this->data[this->size].get_slots();
		this->data[this->size] = Weapon();
		this->size--;
		this->slots += weapon_slots;
	}

	return *this;
}

template<>
bool Equipment<Armor>::operator==(const Equipment<Armor>& other) {
	unsigned int current_armor_score = 0;
	unsigned int other_armor_score = 0;
	
	for (int i = 0; i < this->size; i++) {
		current_armor_score += this->data[i].get_gear_score();
	}

	for (int i = 0; i < other.size; i++) {
		other_armor_score += other.data[i].get_gear_score();
	}

	return current_armor_score == other_armor_score;
}

template<>
bool Equipment<Weapon>::operator==(const Equipment<Weapon>& other) {
	double current_weapon_score = 0;
	double other_weapon_score = 0;
	
	for (int i = 0; i < this->size; i++) {
		current_weapon_score += this->data[i].get_weapon_score();
	}

	for (int i = 0; i < other.size; i++) {
		other_weapon_score += other.data[i].get_weapon_score();
	}

	return current_weapon_score == other_weapon_score;
}

template<typename T>
bool Equipment<T>::operator!=(const Equipment<T>& other) {
	return !(*this == other);
}

template<>
double Equipment<Weapon>::best_equipment() const {
	double max_result = this->data[0].get_weapon_score();

	for (int i = 1; i < this->size; i++) {
		if(this->data[i].get_weapon_score() > max_result) {
			max_result = this->data[i].get_weapon_score();
		}
	}

	return max_result;
}

template<>
double Equipment<Armor>::best_equipment() const {
	double max_result = this->data[0].get_gear_score();

	for (int i = 1; i < this->size; i++) {
		if (this->data[i].get_gear_score() > max_result) {
			max_result = this->data[i].get_gear_score();
		}
	}

	return max_result;
}

template<>
int Equipment<Armor>::get_full_slots() const {
	return 24 - this->slots;
}

template<>
int Equipment<Weapon>::get_full_slots() const {
	return 24 - this->slots;
}

template<typename T>
void Equipment<T>::copy_equipment(const Equipment<T>& from) {
	this->size = from.size;
	this->slots = from.slots;
	this->data = new T[this->slots];

	for (int i = 0; i < this->size; i++) {
		this->data[i] = from.data[i];
	}
}

template<typename T>
void Equipment<T>::clear_everything() {
	delete []this->data;
	this->size = 0;
	this->slots = 24;
}