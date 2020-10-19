#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	bool a_less_than_other_two_sum = (a < b + c);
	bool b_less_than_other_two_sum = (b < a + c);
	bool c_less_than_other_two_sum = (c < a + b);

	if (!a_less_than_other_two_sum ||
		!b_less_than_other_two_sum || 
		!c_less_than_other_two_sum) {

		cout << "Not valid triangle" << endl;
	}
	else {
		cout << "Valid triangle" << endl;
	}

	return 0;
}