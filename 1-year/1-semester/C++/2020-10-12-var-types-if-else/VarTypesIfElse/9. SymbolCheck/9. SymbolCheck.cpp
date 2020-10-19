#include <iostream>

using namespace std;

int main() {
	char symbol;
	cin >> symbol;

	if ((symbol >= 65 && symbol <= 90) ||
		(symbol >= 97 && symbol <= 122)) {

		if (symbol == 'a' || symbol == 'e' ||
			symbol == 'i' || symbol == 'o' || symbol == 'u' ||
			symbol == 'A' || symbol == 'E' || symbol == 'I' ||
			symbol == 'O' || symbol == 'U') {

			cout << "Vowel" << endl;
		}
		else {
			cout << "Not vowel" << endl;
		}
	}
	else {
		cout << "Not a letter" << endl;
	}

	return 0;
}