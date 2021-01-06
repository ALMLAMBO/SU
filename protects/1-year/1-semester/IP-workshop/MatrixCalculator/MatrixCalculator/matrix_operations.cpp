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
		case 1: {
				MatrixRepresentation result_matrix = 
					matrix_multiplication_with_number(
						MATRIX_MULT_FILENAME);

				print_matrix(result_matrix);
				result_matrix.destroy_matrix_values();
			}
			break;

		default:
			cout << "Invalid operation" << endl;
			break;
	}
}

MatrixRepresentation matrix_multiplication_with_number(
	const char* filename) {

	ifstream matrix_mult_number;
	matrix_mult_number.open(filename);

	if (!matrix_mult_number.is_open()) {
		MatrixDimensions dimensions;
		dimensions.set_rows(INT_MIN);
		dimensions.set_columns(INT_MIN);

		MatrixRepresentation matrix(dimensions);
		return matrix;
	}

	MatrixRepresentation matrix = get_matrix(matrix_mult_number);
	double scalar = get_scalar(matrix_mult_number);

	MatrixDimensions dimensions = matrix.get_dimensions();
	MatrixRepresentation result_matrix(dimensions);

	const int ROWS = dimensions.get_rows();
	const int COLUMNS = dimensions.get_columns();

	double** result_matrix_values = new double* [ROWS];

	for (int i = 0; i < ROWS; i++) {
		result_matrix_values[i] = new double[COLUMNS];

		for (int j = 0; j < COLUMNS; j++) {
			result_matrix_values[i][j] = matrix
				.get_values()[i][j] * scalar;
		}
	}

	result_matrix.set_values(result_matrix_values);

	for (int i = 0; i < ROWS; i++) {
		delete[] result_matrix_values[i];
	}

	delete[] result_matrix_values;
	result_matrix_values = NULL;

	return result_matrix;
}