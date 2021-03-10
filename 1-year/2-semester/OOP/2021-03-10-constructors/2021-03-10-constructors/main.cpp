#include <iostream>
#include "FooDynamic.hpp"

using namespace std;

int main() {
	FooDynamic first;
	FooDynamic second(first);

	cout << first.get_value() << " " << second.get_value() << endl;
	first.set_value(3);
	cout << first.get_value() << " " << second.get_value() << endl;

	return 0;
}