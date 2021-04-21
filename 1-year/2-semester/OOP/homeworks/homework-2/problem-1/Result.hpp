#pragma once
#ifndef __RESULT_HPP__
#define __RESULT_HPP__

#include "Optional.hpp"

template<typename T>
class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(T other);
	bool operator==(Error other);

private:
	T result;
	std::string message;
};

template<typename T>
Result<T>::Result() {
	this->result = T();
}

template<typename T>
Result<T>::Result(const T& result) {
	this->result = result;
}

template<typename T>
Result<T>::Result(const std::string& error_message) {
	this->message = error_message;
}

template<typename T>
Optional<T> Result<T>::get_result() const {
	return Optional<T>(this->result);
}

template<typename T>
Optional<Error> Result<T>::get_error() const {
	return Optional<Error>(Error(this->message));
}

template<typename T>
bool Result<T>::operator==(T other) {
	return this->get_error().is_none();
}

template<typename T>
bool Result<T>::operator==(Error other) {
	return !this->get_error().is_none();
}

#endif // !__RESULT_HPP__