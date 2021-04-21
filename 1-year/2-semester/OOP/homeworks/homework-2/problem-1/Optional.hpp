#pragma once
#ifndef __OPTIONAL_HPP__
#define __OPTIONAL_HPP__

#include "Error.hpp"

template<typename T>
class Optional {
public:
    Optional();
    Optional(const T& value);
    Optional(const Optional<T>& from);
    ~Optional();

    Optional<T>& operator=(const Optional<T>& from);

    bool is_none() const;
    T get_value() const;

private:
    T* data;
};

template<typename T>
Optional<T>::Optional() {
	this->data = new T();
}

template<typename T>
Optional<T>::Optional(const T& value) {
	this->data = new T(value);
}

template<typename T>
Optional<T>::Optional(const Optional<T>& from) {
	this->data = new T(*from.data);
}

template<typename T>
Optional<T>::~Optional() {
	delete this->data;
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& from) {
	if (this != &from) {
		delete this->data;
		this->data = new T(*from.data);
	}

	return *this;
}

template<typename T>
bool Optional<T>::is_none() const {
	return this->data == nullptr;
}

template<typename T>
T Optional<T>::get_value() const {
	return *this->data;
}

#endif // !__OPTIONAL_HPP__