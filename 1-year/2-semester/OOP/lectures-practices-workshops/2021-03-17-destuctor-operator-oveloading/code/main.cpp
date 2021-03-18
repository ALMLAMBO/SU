#include <iostream>
#include "DynamicArray.hpp"
#include "Rational.hpp"

using namespace std;

int main() {
    DynamicArray first;

    first.append(1);
    first.append(2);
    first.append(3);

    cout << first.operator[](0) << endl;
    cout << first[0] << endl;

    DynamicArray second(first);
    DynamicArray third;
    third = first;

    first.append(4);

    first.print_memory();
    cout << endl;

    second.print_memory();
    cout << endl;

    third.print_memory();
    cout << endl;

    Rational a(3, 5);
    Rational b(2, 3);
    Rational result = a * b;

    cout << result.to_string() << endl;

	return 0;
}