#include <iostream>
#include <fstream>
#include <string>
#include "matrix_operations.h"
#include "helper_functions.h"
#include "print_functions.h"

using namespace std;

/// <summary>
/// Manages matrix operations
/// </summary>
/// <param name="filename">file to read</param>
/// <param name="option">integer for which operation to choose</param>
void matrix_operations_manager(int option) {
	const char* MATRIX_MULT_FILENAME = "matrix_mult_number.txt";

	switch (option) {
		case 1:
			matrix_multiplication_with_number(MATRIX_MULT_FILENAME);
			break;

		default:
			cout << "Invalid operation" << endl;
			break;
	}
}