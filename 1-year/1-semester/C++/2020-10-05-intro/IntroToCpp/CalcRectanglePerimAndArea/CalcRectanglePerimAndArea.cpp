#include <iostream>

using namespace std;

int main() {
	double width;
	double height;

	cin >> width;
	cin >> height;

	double perim = 2 * (width + height);
	double area = width * height;

	cout << "Perimeter = " << perim << endl;
	cout << "Area = " << area << endl;
}