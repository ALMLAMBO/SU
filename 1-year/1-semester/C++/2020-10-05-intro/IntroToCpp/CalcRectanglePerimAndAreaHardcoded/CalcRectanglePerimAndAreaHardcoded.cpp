#include <iostream>

using namespace std;

int main() {
	double width = 5.4;
	double height = 7.9;

	double perim = 2 * (width + height);
	double area = width * height;

	cout << "Perimeter = " << perim << endl;
	cout << "Area = " << area << endl;
}