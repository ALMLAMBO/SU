#include "FooDynamic.hpp"

FooDynamic::FooDynamic() {
	this->value = new int(0);
}

FooDynamic::FooDynamic(const FooDynamic& other) {
	this->value = new int(*other.value);
}

void FooDynamic::set_value(const int new_value) {
	*(this->value) = new_value;
}

int FooDynamic::get_value() const {
	return *(this->value);
}