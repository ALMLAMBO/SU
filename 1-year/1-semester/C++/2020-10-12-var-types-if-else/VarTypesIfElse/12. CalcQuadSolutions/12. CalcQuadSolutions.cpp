#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;

	double d = pow(b, 2) - 4 * a * c;

	if (d < 0) {
		cout << "No solution" << endl;
	}
	else if (d == 0) {
		double x = -b / 2 * a;
		cout << "One solution: " << x << endl;
	}
	else if (d > 0) {
		double x1 = (-b + sqrt(d)) / 2 * a;
		double x2 = (-b - sqrt(d)) / 2 * a;

		cout << "First solution: " << x1 << endl
			<< "Second solution: " << x2 << endl;
	}

	return 0;
}