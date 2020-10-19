#include <iostream>

using namespace std;

int main() {
	int year;
	cin >> year;

	if (year % 4 == 0) {
		cout << "Leap year" << endl;
	}
	else {
		cout << "Not leap year" << endl;
	}

	return 0;
}