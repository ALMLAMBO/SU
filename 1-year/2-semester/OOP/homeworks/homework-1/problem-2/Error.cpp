#include "Error.hpp"

Error::Error() {
	this->message = nullptr;
	this->error_type = ErrorType::None;
}

Error::Error(const char* init_message, const ErrorType init_type) {
	this->copy_char_array(this->message, init_message);
	this->error_type = init_type;
}

Error::Error(const Error& other) {
	this->copy_error(other);
}

Error::~Error() {
	delete[] this->message;
}

Error& Error::operator=(const Error& other) {
	if (this != &other) {
		delete[] this->message;

		this->copy_error(other);
	}

	return *this;
}

bool Error::hasMessage() const {
	return this->message != nullptr;
}

const char* Error::getMessage() const {
	return this->message;
}

ErrorType Error::getType() const {
	return this->error_type;
}

Error Error::newNone() {
	return Error();
}

Error Error::newBuildFailed(const char* message) {
	return Error(message, ErrorType::BuildFailed);
}

Error Error::newWarning(const char* message) {
	return Error(message, ErrorType::Warning);
}

Error Error::newFailedAssertion(const char* message) {
	return Error(message, ErrorType::FailedAssertion);
}

void Error::copy_char_array(char*& destination, const char* source) {
	if (source == nullptr) {
		destination = nullptr;
	}
	else {
		int len = strlen(source);
		destination = new char[len + 1];
		strcpy(destination, source);
		destination[len] = '\0';
	}
}

void Error::copy_error(const Error& other) {
	this->copy_char_array(this->message, other.message);
	this->error_type = other.error_type;
}