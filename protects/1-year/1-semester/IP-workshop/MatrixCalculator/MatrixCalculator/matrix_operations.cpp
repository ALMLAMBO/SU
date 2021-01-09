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
	const char* MATRIX_DETERMINANT_FILENAME = "matrix_det.txt";
	const char* MATRIX_DIVISION_NUMBER = "matrix_div_number.txt";
	const char* INVERSE_MATRIX = "matrix_inverse.txt";
	const char* TRANSPOSE = "matrix_transpose.txt";

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

		case 3: {
			MatrixRepresentation matrix_to_find_det =
				get_matrix(MATRIX_DETERMINANT_FILENAME);

			double determinant = calculate_matrix_determinant(
				matrix_to_find_det);

			cout << " = " << determinant << endl;
		}

		case 4: {
			MatrixRepresentation matrix_div_number =
				get_matrix(MATRIX_DIVISION_NUMBER);

			double scalar = get_scalar(MATRIX_DIVISION_NUMBER);
			MatrixRepresentation result_matrix_div_number =
				matrix_division_with_number(matrix_div_number, scalar);
		}

		case 5: {
			MatrixRepresentation input_matrix_inverse =
				get_matrix(INVERSE_MATRIX);

			MatrixRepresentation inverse_matrix =
				find_matrix_inverse(input_matrix_inverse);

			cout << endl;
			print_matrix(inverse_matrix);
		}

		case 6: {
			MatrixRepresentation input_transpose =
				get_matrix(TRANSPOSE);

			MatrixRepresentation transpose =
				matrix_transposition(input_transpose);

			cout << endl;
			print_matrix(transpose);
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

	result_matrix.init_empty_matrix_values();
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

	return result_matrix;
}

/// <summary>
/// Calculates matrix determinant using Sarrus's rule
/// </summary>
/// <param name="matrix">input matrix</param>
/// <returns>matrix determinant</returns>
double calculate_matrix_determinant(
	MatrixRepresentation matrix) {

	const int ROWS = matrix
		.get_dimensions().get_rows();
	
	const int COLUMNS = matrix
		.get_dimensions().get_columns();

	double determinant = DBL_MIN;

	if (ROWS == COLUMNS) {
		double main_diagonals_sum = 0;
		double secondary_diagonals_sum = 0;
		double main_diagonal_mult = 1;
		double secondary_diagonal_mult = 1;

		double** extended_matrix_values = new double* [ROWS];
		int extended_matrix_columns = COLUMNS * 2 - 1;
		for (int i = 0; i < ROWS; i++) {
			extended_matrix_values[i] = 
				new double[extended_matrix_columns];

			for (int j = 0; j < COLUMNS; j++) {
				extended_matrix_values[i][j] = matrix
					.get_values()[i][j];
			}

			for (int j = 0; j < COLUMNS - 1; j++) {
				extended_matrix_values[i][COLUMNS + j] = matrix
					.get_values()[i][j];
			}
		}

		int middle_column = COLUMNS - 1;

		for (int i = 0; i < ROWS; i++) {
			main_diagonal_mult *=
				extended_matrix_values[i][i + middle_column];

			secondary_diagonal_mult *=
				extended_matrix_values[i][middle_column - i];
		}

		main_diagonals_sum += main_diagonal_mult;
		secondary_diagonals_sum += secondary_diagonal_mult;
		main_diagonal_mult = 1;
		secondary_diagonal_mult = 1;

		int rows_between_first_last = ROWS - 2;

		for (int k = 1; k <= rows_between_first_last; k++) {
			for (int i = 0; i < ROWS; i++) {
				int second_index = middle_column + k;

				main_diagonal_mult *=
					extended_matrix_values[i][second_index];

				secondary_diagonal_mult *=
					extended_matrix_values[i][second_index - i];
			}

			main_diagonals_sum += main_diagonal_mult;
			secondary_diagonals_sum += secondary_diagonal_mult;
			main_diagonal_mult = 1;
			secondary_diagonal_mult = 1;
		}

		for (int i = 0; i < COLUMNS; i++) {
			main_diagonal_mult *=
				extended_matrix_values[i][i];

			secondary_diagonal_mult *=
				extended_matrix_values[i][extended_matrix_columns - i];
		}

		determinant = main_diagonals_sum - secondary_diagonals_sum;
	}

	return determinant;
}

/// <summary>
/// Divides matrix with given number if it is possible
/// </summary>
/// <param name="matrix">input matrix</param>
/// <param name="scalar">number to divide matrix</param>
/// <returns>result after division</returns>
MatrixRepresentation matrix_division_with_number(
	MatrixRepresentation matrix, double scalar) {

	const int ROWS = matrix.get_dimensions().get_rows();
	const int COLUMNS = matrix.get_dimensions().get_columns();

	MatrixDimensions result_matrix_dimensions;
	result_matrix_dimensions.set_rows(ROWS);
	result_matrix_dimensions.set_columns(COLUMNS);
	MatrixRepresentation result_matrix(result_matrix_dimensions);

	if (scalar != 0) {
		result_matrix.init_empty_matrix_values();
		double** result_matrix_values = new double* [ROWS];

		for (int i = 0; i < ROWS; i++) {
			result_matrix_values[i] = new double[COLUMNS];

			for (int j = 0; j < COLUMNS; j++) {
				result_matrix_values[i][j] = matrix
					.get_values()[i][j] / scalar;
			}
		}

		result_matrix.set_values(result_matrix_values);

		for (int i = 0; i < ROWS; i++) {
			delete[] result_matrix_values[i];
		}

		delete[] result_matrix_values;
		result_matrix_values = NULL;
	}
	else {
		return result_matrix;
	}

	return result_matrix;
}

/// <summary>
/// finds matrix inverse from given one
/// </summary>
/// <param name="matrix">input matrix</param>
/// <returns>inverse matrix if exists</returns>
MatrixRepresentation find_matrix_inverse(
	MatrixRepresentation matrix) {

	const int ROWS = matrix.get_dimensions().get_rows();
	const int COLUMNS = matrix.get_dimensions().get_columns();

	MatrixDimensions inverse_matrix_dimensions;
	inverse_matrix_dimensions.set_rows(ROWS);
	inverse_matrix_dimensions.set_columns(COLUMNS);
	MatrixRepresentation inverse_matrix(inverse_matrix_dimensions);

	if (ROWS == COLUMNS) {
		double determinant = 
			calculate_matrix_determinant(matrix);
	
		if (determinant != 0) {
			double** matrix_values = new double* [ROWS];
			for (int i = 0; i < ROWS; i++) {
				matrix_values[i] = new double[COLUMNS];
			}

			const int SUB_MATRIX_ROWS = ROWS - 1;
			const int SUB_MATRIX_COLUMNS = COLUMNS - 1;
			MatrixDimensions sub_matrix_dimensions;

			sub_matrix_dimensions.set_rows(SUB_MATRIX_ROWS);
			sub_matrix_dimensions.set_columns(SUB_MATRIX_COLUMNS);

			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					double** sub_matrix_values =
						new double* [SUB_MATRIX_ROWS];

					for (int k = 0; i < SUB_MATRIX_ROWS; i++) {
						sub_matrix_values[i] = 
							new double[SUB_MATRIX_COLUMNS];

						for (int l = 0; i < SUB_MATRIX_COLUMNS; j++) {
							if (k != i && l != j) {
								sub_matrix_values[k][l] =
									matrix.get_values()[k][l];
							}
						}
					}

					MatrixRepresentation sub_matrix(sub_matrix_dimensions);
					sub_matrix.set_values(sub_matrix_values);

					double sub_determinant =
						calculate_matrix_determinant(sub_matrix);

					matrix_values[j][i] = sub_determinant;

					for (int k = 0; k < SUB_MATRIX_ROWS; k++) {
						delete[] sub_matrix_values[k];
					}

					delete[] sub_matrix_values;
					sub_matrix_values = NULL;
				}
			}

			inverse_matrix.set_values(matrix_values);
			
			for (int i = 0; i < ROWS; i++) {
				delete[] matrix_values[i];
			}

			delete[] matrix_values;
			matrix_values = NULL;
		}
	}
	else {
		return inverse_matrix;
	}

	return inverse_matrix;
}

/// <summary>
/// Transpose a matrix
/// </summary>
/// <param name="matrix">input matrix</param>
/// <returns>transposed matrix</returns>
MatrixRepresentation matrix_transposition(
	MatrixRepresentation matrix) {

	const int ROWS = matrix.get_dimensions().get_rows();
	const int COLUMNS = matrix.get_dimensions().get_columns();

	MatrixDimensions result_matrix_dimensions;
	result_matrix_dimensions.set_rows(COLUMNS);
	result_matrix_dimensions.set_columns(ROWS);
	MatrixRepresentation result_matrix(result_matrix_dimensions);

	double** result_matrix_values = new double* [ROWS];

	for (int i = 0; i < ROWS; i++) {
		result_matrix_values[i] = new double[COLUMNS];

		for (int j = 0; j < COLUMNS; j++) {
			result_matrix_values[i][j] = matrix
				.get_values()[j][i];
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