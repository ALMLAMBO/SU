#include "DynamicArray.hpp"

DynamicArray::DynamicArray() : 
	capacity(1), length(0), content(new int[capacity]) { }

DynamicArray::DynamicArray(const DynamicArray& from) :
	length(from.length), capacity(from.capacity) {

	this->content = new int[this->capacity];
	for (int i = 0; i < from.length; i++) {
		this->content[i] = from.content[i];
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray& from) {
	if (this != &from) {
		this->length = from.length;
		this->capacity = from.capacity;

		delete[] this->content;
		this->content = new int[this->capacity];

		for (int i = 0; i < this->length; i++) {
			this->content[i] = from.content[i];
		}
	}
	return *this;
}

DynamicArray::~DynamicArray() {
	std::cout << "Destructor called" << std::endl;
	delete[] this->content;
}

void DynamicArray::append(const int& item) {
	if (this->length == this->capacity) {
		this->capacity *= 2;
		int* new_content = new int[this->capacity];

		for (int i = 0; i < this->length; i++) {
			new_content[i] = this->content[i];
		}

		delete[] this->content;
		this->content = new_content;
	}

	this->content[this->length++] = item;
}

int DynamicArray::get(const int& index) const {
	if (0 <= index && index < this->length) {
		return this->content[index];
	}

	return -1;
}

int DynamicArray::get_length() const {
	return this->length;
}

int DynamicArray::operator[](const int index) {
	return this->get(index);
}