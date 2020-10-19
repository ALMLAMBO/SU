#include <iostream>

using namespace std;

int main() {
	int num1, num2;

	cin >> num1 >> num2;

	if (num1 < num2) {
		cout << "Min = " << num1 << endl
			<< "Max = " << num2 << endl;
	}
	else if (num1 > num2) {
		cout << "Min = " << num2 << endl
			<< "Max = " << num1 << endl;
	}
	else if (num1 == num2) {
		cout << "Min = Max = " << num1 << endl;
	}
}