#include <iostream>
#include "Pair.hpp"

using namespace std;

int main() {
	Pair<int, double> p;
	Pair<int, double> p2(1, 3);
	p.set_pair(1, 3.14);

	cout << p.get_key() << endl;
	cout << p.get_value() << endl;
	cout << boolalpha << (p != p2) << endl;

	return 0;
}