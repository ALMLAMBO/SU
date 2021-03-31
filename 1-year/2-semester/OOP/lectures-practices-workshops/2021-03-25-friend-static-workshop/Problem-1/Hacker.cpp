#include "Hacker.hpp"

bool Hacker::guess_number(const Safe& safe, const int& number) {
	bool guessed;
	
	if (number == safe.number) {
		guessed = true;
	}
	else {
		guessed = false;
	}

	return guessed;
}