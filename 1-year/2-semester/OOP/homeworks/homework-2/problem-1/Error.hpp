#pragma once
#ifndef __ERROR_HPP__
#define __ERROR_HPP__

#include <string>

class Error {
public:
	Error(const std::string& message = "");
	std::string get_message() const;

private:
	std::string message;
};


#endif // !__ERROR_HPP__