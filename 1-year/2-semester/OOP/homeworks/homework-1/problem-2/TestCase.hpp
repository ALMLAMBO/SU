#pragma once
#ifndef __TEST_CASE_HPP__
#define __TEST_CASE_HPP__

#include <string>
#include "Error.hpp"

class TestCase {
public:
	TestCase(const std::string& name = "", const Error& error = Error::newNone());

	std::string getName() const;
	bool isPassing() const;
	bool hasError() const;
	ErrorType getErrorType() const;
	std::string getErrorMessage() const;
	bool operator==(const TestCase& other);

private:
	std::string name;
	Error error;
};

#endif // !__TEST_CASE_HPP__
