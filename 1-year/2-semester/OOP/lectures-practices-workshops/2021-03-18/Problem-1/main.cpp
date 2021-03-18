#include <iostream>
#include "Laptop.hpp"

using namespace std;

int main() {
	Laptop laptop("Asus", "Tuf gaming", 2000, 15.6,
		Processor(4.2, 6, 8), Ram(2666, 16), 100);

	cout << laptop;
	Laptop a;
	bool result = laptop == a;

	cout << endl << boolalpha << result << endl;

	return 0;
}