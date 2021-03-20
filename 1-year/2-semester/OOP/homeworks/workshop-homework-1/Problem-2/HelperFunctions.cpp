#include "HelperFunctions.hpp"

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