#include "Inventory.hpp"

//std::ostream& operator<<(std::ostream& out,
//	const Inventory<Backpack<Money>>& inventory) {
//
//	return out;
//}
//
//std::ostream& operator<<(std::ostream& out,
//	const Inventory<Backpack<Materials>>& inventory) {
//
//	return out;
//}
//
//std::ostream& operator<<(std::ostream& out,
//	const Inventory<Equipment<Armor>>& inventory) {
//
//	return out;
//}
//
//std::ostream& operator<<(std::ostream& out,
//	const Inventory<Equipment<Weapon>>& inventory) {
//
//	return out;
//}

template<>
bool Inventory<Backpack<Money>>::operator==(
	const Inventory<Backpack<Money>>& other) {
	
	return this->data.get_slots() == other.data.get_slots();
}

template<>
bool Inventory<Backpack<Materials>>::operator==(
	const Inventory<Backpack<Materials>>& other) {
	
	return this->data.get_slots() == other.data.get_slots();
}

template<>
bool Inventory<Equipment<Armor>>::operator==(
	const Inventory<Equipment<Armor>>& other) {
	
	return this->data.get_full_slots() == other.data.get_full_slots();
}

template<>
bool Inventory<Equipment<Weapon>>::operator==(
	const Inventory<Equipment<Weapon>>& other) {
	
	return this->data.get_full_slots() == other.data.get_full_slots();
}

template<>
bool Inventory<Backpack<Money>>::operator!=(
	const Inventory<Backpack<Money>>& other) {
	
	return !(*this == other);
}

template<>
bool Inventory<Backpack<Materials>>::operator!=(
	const Inventory<Backpack<Materials>>& other) {
	
	return !(*this == other);
}

template<>
bool Inventory<Equipment<Armor>>::operator!=(
	const Inventory<Equipment<Armor>>& other) {
	
	return !(*this == other);
}

template<>
bool Inventory<Equipment<Weapon>>::operator!=(
	const Inventory<Equipment<Weapon>>& other) {
	
	return !(*this == other);
}