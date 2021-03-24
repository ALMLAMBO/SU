/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 2
* @compiler VC
*/
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
