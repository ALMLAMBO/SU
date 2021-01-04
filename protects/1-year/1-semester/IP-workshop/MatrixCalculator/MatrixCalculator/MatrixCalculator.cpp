#include <iostream>
#include "print_functions.h"
#include "matrix_operations.h"

using namespace std;

int main() {
	int option;

	print_available_operations();
	cout << endl << "Enter option" << endl;
	cin >> option;
	
	matrix_operations_manager(option);
}