#pragma once
#ifndef __HELPER_FUNCTIONS_HPP__
#define __HELPER_FUNCTIONS_HPP__
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

class HelperFunctions {
public:
	static char* copy_char_array(const char* source, int max_length);
};

#endif // !__HELPER_FUNCTIONS_HPP__
