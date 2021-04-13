#include "Backpack.hpp"

template<>
Backpack<Materials>::Backpack() {
	this->slots = 16;
}

template<>
Backpack<Money>::Backpack() {
	this->slots = 0;
}

template<>
bool Backpack<Materials>::is_full() const {
	return this->slots == 0;
}

template<>
bool Backpack<Money>::is_full() const {
	return false;
}

template<typename T>
bool Backpack<T>::is_empty() const {
	return this->data.size() == 0;
}

template<>
Backpack<Materials>& Backpack<Materials>::clear() {
	this->data.clear();
	this->slots = 16;

	return *this;
}

template<>
Backpack<Money>& Backpack<Money>::clear() {
	this->data.clear();

	return *this;
}

template<>
Backpack<Money>& Backpack<Money>::add(const Money& item) {
	this->data.push_back(item);

	return *this;
}

template<typename T>
Backpack<T>& Backpack<T>::remove() {
	return *this;
}

template<>
int Backpack<Materials>::get_slots() const {
	return 16 - this->slots;
}

template<>
int Backpack<Money>::get_slots() const {
	return this->data.size();
}

//void a() {
//	std::map<MaterialType, unsigned int> b;
//	int total_slots = 0;
//
//	for (std::pair< MaterialType, unsigned int> pair : b) {
//		if (pair.first == MaterialType::essence) {
//			total_slots += pair.second / 10;
//			if (pair.second % 10 != 0) {
//				total_slots++;
//			}
//		}
//		else {
//			total_slots += pair.second / 20;
//			if (pair.second % 20 != 0) {
//				total_slots++;
//			}
//		}
//	}
//}