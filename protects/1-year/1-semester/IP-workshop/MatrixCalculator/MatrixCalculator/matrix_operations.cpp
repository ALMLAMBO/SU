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
	const char* MATRICES_MULT_FIRST_MATRIX = "matrix_mult_first.txt";
	const char* MATRICES_MULT_SECOND_MATRIX = "matrix_mult_second.txt";

	switch (option) {
		case 1: {
				MatrixRepresentation result_matrix = 
					matrix_multiplication_with_number(
						MATRIX_MULT_FILENAME);

				print_matrix(result_matrix);
				result_matrix.destroy_matrix_values();
			}
			break;

		case 2: {
			MatrixRepresentation first_matrix =
				get_matrix(MATRICES_MULT_FIRST_MATRIX);

			MatrixRepresentation second_matrix =
				get_matrix(MATRICES_MULT_SECOND_MATRIX);

			MatrixRepresentation result_matrix =
				matrices_multiplication(first_matrix, second_matrix);

			print_matrix(result_matrix);

			break;
		}

		default:
			cout << "Invalid operation" << endl;
			break;
	}
}

MatrixRepresentation matrix_multiplication_with_number(
	const char* filename) {

	MatrixRepresentation matrix = get_matrix(filename);
	double scalar = get_scalar(filename);

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

/// <summary>
/// Multiplies two matrices
/// </summary>
/// <param name="first_matrix">left matrix</param>
/// <param name="second_matrix">right matrix</param>
/// <returns>result matrix after multiplication</returns>
MatrixRepresentation matrices_multiplication(
	MatrixRepresentation first_matrix,
	MatrixRepresentation second_matrix) {

	const int ROWS_FIRST_MATRIX = first_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_FIRST_MATRIX = first_matrix
		.get_dimensions().get_columns();

	const int ROWS_SECOND_MATRIX = second_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_SECOND_MATRIX = second_matrix
		.get_dimensions().get_rows();

	MatrixDimensions result_matrix_dimensions;
	result_matrix_dimensions.set_rows(ROWS_FIRST_MATRIX);
	result_matrix_dimensions.set_columns(COLUMNS_SECOND_MATRIX);
	MatrixRepresentation result_matrix(result_matrix_dimensions);

	if (COLUMNS_FIRST_MATRIX == ROWS_SECOND_MATRIX) {
		result_matrix.init_empty_matrix_values();

		double** result_matrix_values = new double* [ROWS_FIRST_MATRIX];
		for (int i = 0; i < ROWS_FIRST_MATRIX; i++) {
			result_matrix_values[i] = new double[COLUMNS_SECOND_MATRIX];
		}

		for (int i = 0; i < ROWS_FIRST_MATRIX; i++) {
			for (int j = 0; j < COLUMNS_SECOND_MATRIX; j++) {
				for (int k = 0; k < COLUMNS_FIRST_MATRIX; i++) {
					result_matrix_values[i][j] +=
						first_matrix.get_values()[i][k] *
						second_matrix.get_values()[k][j];
				}
			}
		}

		result_matrix.set_values(result_matrix_values);

		for (int i = 0; i < ROWS_FIRST_MATRIX; i++) {
			delete[] result_matrix_values[i];
		}

		delete[] result_matrix_values;
		result_matrix_values = NULL;
	}
	else {
		return result_matrix;
	}
}