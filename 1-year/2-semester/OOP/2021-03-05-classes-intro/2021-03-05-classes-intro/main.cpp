#include "Rational.h"
#include <iostream>

using namespace std;

int main() {

	Rational r = Rational(3, 4);
	r.print();
	cout << endl;
	
	Rational q;
	q.read();
	q.print();
	cout << endl;

	Rational p = add(r, q);
	r.print(); cout << " + "; q.print(); cout << " = ";
	p.print(); cout << endl;
	
	multiply(r, q).print(); cout << endl;
	divide(r, q).print(); cout << endl;

	return 0;
}
