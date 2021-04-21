#include <iostream>
#include "Vector4D.hpp"

using namespace std;

int main() {
	Vector4D v(1, 2, 3, 4);
	Vector4D v2(1, 2, 30, 40);

	/*cout << v[0] << endl;
	v[0] = 20;
	cout << v[0] << endl;
	*/
	cout << (v <= v2) << endl;
	return 0;
}