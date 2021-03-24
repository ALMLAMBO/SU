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
#include "HelperFunctions.hpp"

/// <summary>
/// Copy char array
/// </summary>
/// <param name="source">data to copy</param>
/// <param name="max_length">maximum allowed length if it is 0 endless</param>
/// <returns>copied data</returns>
char* HelperFunctions::copy_char_array(
	const char* source, int max_length) {

	int len = strlen(source);
	
	if (len > max_length && max_length != 0) {
		return new char[1]{ '\0' };
	}

	char* destination = new char[len + 1];
	strcpy(destination, source);
	destination[len] = '\0';

	return destination;
}