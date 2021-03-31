#include <iostream>
#include <random>
#include "Safe.hpp"

using namespace std;

void generate_number(Safe& safe) {
	random_device rd; 
	mt19937 gen(rd());
	uniform_int_distribution<> distr;
	safe.number = distr(gen);
}

int main() {
	Safe safe;
	generate_number(safe);

	Hacker hacker;

	cout << boolalpha << hacker.guess_number(2) << endl;
	
	return 0;
}