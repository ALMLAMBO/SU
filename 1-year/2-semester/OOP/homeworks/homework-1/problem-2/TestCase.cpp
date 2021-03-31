#include "TestCase.hpp"

TestCase::TestCase(const std::string& name,
	const Error& error) {

	this->name = name;
	this->error = error;
}

std::string TestCase::getName() const {
	return this->name;
}

bool TestCase::isPassing() const {
	return this->error.getType() == ErrorType::None
		|| this->error.getType() == ErrorType::Warning;
}

bool TestCase::hasError() const {
	return this->error.getType() != ErrorType::None;
}

ErrorType TestCase::getErrorType() const {
	return this->error.getType();
}

std::string TestCase::getErrorMessage() const {
	std::string error_message;

	if (!this->error.hasMessage()) {
		error_message = "";
	}
	else {
		error_message = std::string(this->error.getMessage());
	}

	return error_message;
}

bool TestCase::operator==(const TestCase& other) {
	return this->name == other.name;
}