#include "HelperFunctions.hpp"

char* HelperFunctions::copy_char_array(
	const char* source, int max_length) {

	int len = strlen(source);
	
	if (len > max_length) {
		return NULL;
	}

	char* destination = new char[len + 1];
	strcpy_s(destination, len, source);

	return destination;
}