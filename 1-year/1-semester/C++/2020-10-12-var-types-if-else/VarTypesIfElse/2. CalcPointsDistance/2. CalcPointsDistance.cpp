#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	float x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	float x_delta = abs(x1 - x2);
	float y_delta = abs(y1 - y2);

	float distance = sqrt(x_delta * x_delta + y_delta * y_delta);

	cout << fixed << setprecision(2) << distance << endl;
}