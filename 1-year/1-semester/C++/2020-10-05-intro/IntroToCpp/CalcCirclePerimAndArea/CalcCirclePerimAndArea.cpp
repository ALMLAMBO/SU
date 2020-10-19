#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double radius;

	cin >> radius;

	double perim = 2 * M_PI * radius;
	double area = pow(radius, 2) * M_PI;

	cout << "Perimeter = " << perim << endl;
	cout << "Area = " << area << endl;
}