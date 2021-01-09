#include <iostream>
#include <algorithm>
#include <iomanip>
#include "print_functions.h"
#include "matrix_operations.h"
#include "helper_functions.h"

using namespace std;

/// <summary>
/// Prints available operations with matrices
/// </summary>
void print_available_operations() {
	cout << "1. Matrix multiplication with number" << endl;
	cout << "2. Matrices multiplication" << endl;
	cout << "3. Find matrix determinant" << endl;
	cout << "4. Matrix division with number" << endl;
	cout << "5. Find inverse matrix" << endl;
	cout << "6. Matrix transpose" << endl;
	cout << "(Optional)7. Matrices sum" << endl;
	cout << "(Optional)8. Matrices subtraction" << endl;
	cout << "(Optional)9. Matrices division" << endl;
}

/// <summary>
/// Prints matrix
/// </summary>
/// <param name="matrix">matrix to print</param>
void print_matrix(MatrixRepresentation& matrix) {
	if (matrix.get_values() != NULL) {
		const int ROWS = matrix.get_dimensions().get_rows();
		const int COLUMNS = matrix.get_dimensions().get_columns();
		const char BEGIN_END_ROW = (char)186;
		MatrixElementsLength elements_lengths =
			get_matrix_elements_lengths(matrix);
		
		int* longest_numbers = new int[COLUMNS];

		for (int i = 0; i < ROWS; i++) {
			int* column_begin = elements_lengths
				.get_elements_lengths() + i * COLUMNS;

			int* column_end = elements_lengths
				.get_elements_lengths() + ((i + 1) * COLUMNS);

			int longest_number = *max_element(
				column_begin, column_end);

			longest_numbers[i] = longest_number;
		}

		for (int i = 0; i < ROWS; i++) {
			cout << BEGIN_END_ROW;

			for (int j = 0; j < COLUMNS; j++) {
				cout << setw(longest_numbers[j])
					<< matrix.get_values()[i][j];

				if (j != COLUMNS - 1) {
					cout << " ";
				}
			}

			cout << BEGIN_END_ROW << endl;
		}
	}
	else {
		cout << "NaN" << endl;
	}
}