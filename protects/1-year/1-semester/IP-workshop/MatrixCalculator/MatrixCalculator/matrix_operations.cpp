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

			break;
		}

		case 3: {
			MatrixRepresentation matrix_to_find_det =
				get_matrix(MATRIX_DETERMINANT_FILENAME);

			double determinant = calculate_matrix_determinant(
				matrix_to_find_det);

			break;
		}

		case 4: {
			MatrixRepresentation matrix_div_number =
				get_matrix(MATRIX_DIVISION_NUMBER);

			double scalar = get_scalar(MATRIX_DIVISION_NUMBER);
			MatrixRepresentation result_matrix_div_number =
				matrix_division_with_number(matrix_div_number, scalar);
			
			result_matrix_div_number.destroy_matrix_values();
			break;
		}

		case 5: {
			MatrixRepresentation input_matrix_inverse =
				get_matrix(INVERSE_MATRIX);

			MatrixRepresentation inverse_matrix =
				find_matrix_inverse(input_matrix_inverse);

			break;
		}

		case 6: {
			MatrixRepresentation input_transpose =
				get_matrix(TRANSPOSE);

			MatrixRepresentation transpose =
				matrix_transposition(input_transpose);

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

	result_matrix.init_empty_matrix_values();
	result_matrix.set_values(result_matrix_values);

	for (int i = 0; i < ROWS; i++) {
		delete[] result_matrix_values[i];
	}

	delete[] result_matrix_values;
	result_matrix_values = NULL;

	print_matrix_mult_divide_number(
		matrix, result_matrix, '*',
		true, scalar);

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
		.get_dimensions().get_columns();

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
				double sum_result_matrix_element = 0;
				
				for (int k = 0; k < COLUMNS_FIRST_MATRIX; k++) {
					double number_from_first_matrix = 
						first_matrix.get_values()[i][k];
					
					double number_from_second_matrix = 
						second_matrix.get_values()[k][j];

					double mult_input_matrices_elements = 
						number_from_first_matrix * number_from_second_matrix;

					sum_result_matrix_element += mult_input_matrices_elements;
				}

				result_matrix_values[i][j] = sum_result_matrix_element;
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

	print_matrices_operations(
		first_matrix, second_matrix,
		result_matrix, '*');

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
	bool determinant_exists = false;
	
	if (ROWS == COLUMNS) {
		double main_diagonals_sum = 0;
		double secondary_diagonals_sum = 0;
		double main_diagonal_mult = 1;
		double secondary_diagonal_mult = 1;

		if (ROWS == 2) {
			determinant += matrix.get_values()[0][0] *
				matrix.get_values()[1][1];

			determinant -= matrix.get_values()[0][1] *
				matrix.get_values()[1][0];

			return determinant;
		}

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

		for (int k = 0; k < COLUMNS; k++) {
			for (int i = 0; i < ROWS; i++) {
				int main_diagonal_element = 
					extended_matrix_values[i][middle_column - k + i];
				
				int secondary_diagonal_element = 
					extended_matrix_values[i][middle_column + k - i];

				main_diagonal_mult *= main_diagonal_element;
				secondary_diagonal_mult *= secondary_diagonal_element;
			}

			main_diagonals_sum += main_diagonal_mult;
			secondary_diagonals_sum += secondary_diagonal_mult;
			main_diagonal_mult = 1;
			secondary_diagonal_mult = 1;
		}

		determinant = main_diagonals_sum - secondary_diagonals_sum;
		determinant_exists = true;
	}

	print_matrix_det(matrix, determinant, determinant_exists);
	cout << endl;

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

	print_matrix_mult_divide_number(
		matrix, result_matrix, '/',
		false, scalar);

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

			double matrix_values_multiplier = 1 / determinant;
			bool plus_sign = true;
			const int SUB_MATRIX_SIZE = ROWS - 1;
			MatrixDimensions sub_matrix_dimensions;
			sub_matrix_dimensions.set_rows(SUB_MATRIX_SIZE);
			sub_matrix_dimensions.set_columns(SUB_MATRIX_SIZE);

			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					double** sub_matrix_values = new double* [SUB_MATRIX_SIZE];

					for (int k = 0; k < SUB_MATRIX_SIZE; k++) {
						sub_matrix_values[k] = new double[SUB_MATRIX_SIZE];
					}

					int row = 0, col = 0;
					for (int k = 0; k < ROWS; k++) {
						for (int l = 0; l < COLUMNS; l++) {
							if (k != i && l != j) {
								sub_matrix_values[row][col] =
									matrix.get_values()[k][l];

								col++;
								if (col == SUB_MATRIX_SIZE) {
									col = 0;
									row++;
								}
							}
						}
					}

					MatrixRepresentation sub_matrix(sub_matrix_dimensions);
					sub_matrix.init_empty_matrix_values();
					sub_matrix.set_values(sub_matrix_values);

					double sub_det = calculate_matrix_determinant(
						sub_matrix) * matrix_values_multiplier;

					if (!plus_sign) {
						sub_det = -sub_det;
						plus_sign = true;
					}
					else {
						plus_sign = false;
					}

					matrix_values[j][i] = sub_det;

					for (int k = 0; k < SUB_MATRIX_SIZE; k++) {
						delete[] sub_matrix_values[k];
					}

					delete[] sub_matrix_values;
					sub_matrix_values = NULL;
				}
			}

			inverse_matrix.init_empty_matrix_values();
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
	print_matrix_inverse(matrix, inverse_matrix);

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
	result_matrix.init_empty_matrix_values();

	double** result_matrix_values = new double* [COLUMNS];

	for (int i = 0; i < COLUMNS; i++) {
		result_matrix_values[i] = new double[ROWS];
	}

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			result_matrix_values[i][j] = 
				matrix.get_values()[j][i];
		}
	}

	result_matrix.set_values(result_matrix_values);

	for (int i = 0; i < COLUMNS; i++) {
		delete[] result_matrix_values[i];
	}

	delete[] result_matrix_values;
	result_matrix_values = NULL;

	print_matrix_transpose(matrix, result_matrix);
	return result_matrix;
}