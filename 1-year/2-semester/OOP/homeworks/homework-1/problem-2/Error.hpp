#pragma once
#ifndef __ERROR_HPP__
#define __ERROR_HPP__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

enum class ErrorType {
	None,
	BuildFailed,
	Warning,
	FailedAssertion,
};

class Error {	
public:
	Error();
	Error(const char* init_message, const ErrorType init_type);
	Error(const Error& other);
	~Error();
	Error& operator=(const Error& other);

	bool hasMessage() const;
	const char* getMessage() const;
	ErrorType getType() const;

	static Error newNone();
	static Error newBuildFailed(const char* message);
	static Error newWarning(const char* message);
	static Error newFailedAssertion(const char* message);

private:
	char* message;
	ErrorType error_type;
	
	void copy_char_array(char*& destination, const char* source);
	void copy_error(const Error& other);
};

#endif // !__ERROR_HPP__
