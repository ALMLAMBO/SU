#include "HelperFunctions.hpp"

char* HelperFunctions::copy_char_array(
	const char* source, int max_length) {

	int len = strlen(source);
	
	if (len > max_length) {
		return new char[1]{ '\0' };
	}

	char* destination = new char[len + 1];
	strcpy(destination, source);

	return destination;
}