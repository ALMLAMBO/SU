#include <iostream>
#include "drink.hpp"
#include "VendingMachine.hpp"

using namespace std;

int main() {
	Drink d("fanta", 100, 1, 1.2);
	cout << d.get_name() << endl;

	d.set_name("coca cola");
	cout << d.get_name() << endl;

	VendingMachine machine;
	machine.add_drink(d);
	cout << boolalpha << machine.add_drink(d) << endl;

	cout << machine.buy_drink("coca cola", 1.3) << endl;
	cout << machine.get_income() << endl;

	machine.add_drink(d);
	cout << machine.buy_drink("coca cola", 1) << endl;
	cout << machine.get_income() << endl;

	return 0;
}