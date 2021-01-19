/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @compiler VC
*
* <file with print functions>
*
*/

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
}

void print_matrix(char matrix_letter, MatrixRepresentation matrix) {
	const int ROWS = matrix
		.get_dimensions().get_rows();

	const int COLUMNS = matrix
		.get_dimensions().get_columns();

	const char* EMPTY_STRING = "    ";
	char BEGIN_END_ROW_SYMBOL = (char)((unsigned int)186);

	LongestElementsLengths longest_elements =
		get_columns_longest_elements(matrix, COLUMNS);

	int row_to_print_matrix_letter = ROWS / 2;

	for (int i = 0; i < ROWS; i++) {
		if (i == row_to_print_matrix_letter) {
			cout << matrix_letter << " = ";
		}
		else {
			cout << EMPTY_STRING;
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS; j++) {
			int column_longest_number =
				longest_elements
				.get_elements_lengths()[j];

			cout << setw(column_longest_number) <<
				matrix.get_values()[i][j];

			if (j != COLUMNS - 1) {
				cout << " ";
			}
		}
		cout << BEGIN_END_ROW_SYMBOL << endl;
	}
	cout << endl << endl;

	longest_elements.destroy_elements_elements_lengths();
}

/// <summary>
/// Prints matrices after operations with two matrices
/// </summary>
/// <param name="first_input_matrix">left matrix</param>
/// <param name="second_input_matrix">right matrix</param>
/// <param name="result_matrix">matrix after operation</param>
/// <param name="operation_symbol">symbol for add, substract, multiply and divide</param>
void print_matrices_operations(
	MatrixRepresentation first_input_matrix,
	MatrixRepresentation second_input_matrix,
	MatrixRepresentation result_matrix,
	char operation_symbol) {

	const int ROWS_RESULT_MATRIX =
		result_matrix.get_dimensions().get_rows();

	const int COLUMNS_RESULT_MATRIX =
		result_matrix.get_dimensions().get_columns();

	char BEGIN_END_ROW_SYMBOL = (char)((unsigned int)186);

	LongestElementsLengths result_matrix_longest_elements =
		get_columns_longest_elements(
			result_matrix, COLUMNS_RESULT_MATRIX);

	print_matrix('A', first_input_matrix);
	print_matrix('B', second_input_matrix);

	int row_to_print_equal_sign = ROWS_RESULT_MATRIX / 2;

	for (int i = 0; i < ROWS_RESULT_MATRIX; i++) {
		if (i == row_to_print_equal_sign) {
			cout << "A " << operation_symbol << " B = ";
		}
		else {
			for (int k = 0; k < 8; k++) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS_RESULT_MATRIX; j++) {
			int column_longest_number =
				result_matrix_longest_elements
				.get_elements_lengths()[j];

			cout << setw(column_longest_number)
				<< result_matrix.get_values()[i][j];

			if (j != COLUMNS_RESULT_MATRIX - 1) {
				cout << " ";
			}
		}
		cout << BEGIN_END_ROW_SYMBOL << endl;
	}

	result_matrix_longest_elements
		.destroy_elements_elements_lengths();

	first_input_matrix.destroy_matrix_values();
	second_input_matrix.destroy_matrix_values();
	result_matrix.destroy_matrix_values();
}

void print_matrix_mult_divide_number(
	MatrixRepresentation input_matrix,
	MatrixRepresentation result_matrix,
	char operation_symbol,
	bool multiply,
	double scalar) {

	const char* EMPTY_STRING = "   ";
	char BEGIN_END_ROW_SYMBOL = (char)((unsigned int)186);
	const int ROWS_INPUT_MATRIX = input_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_INPUT_MATRIX = input_matrix
		.get_dimensions().get_columns();

	LongestElementsLengths input_matrix_longest_elements_lengths =
		get_columns_longest_elements(
			input_matrix, COLUMNS_INPUT_MATRIX);

	LongestElementsLengths result_matrix_longest_elements_lengths =
		get_columns_longest_elements(
			result_matrix, COLUMNS_INPUT_MATRIX);

	int row_to_print_text_symbol_scalar = ROWS_INPUT_MATRIX / 2;
	int scalar_length = get_element_length(scalar);

	for (int i = 0; i < ROWS_INPUT_MATRIX; i++) {
		if (i == row_to_print_text_symbol_scalar) {
			if (multiply) {
				cout << scalar << " "
					<< operation_symbol << " ";
			}
		}
		else if (multiply) {
			for (int k = 0; k < scalar_length + 3; k++) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;

		for (int j = 0; j < COLUMNS_INPUT_MATRIX; j++) {
			int column_longest_number =
				input_matrix_longest_elements_lengths
				.get_elements_lengths()[j];

			cout << setw(column_longest_number)
				<< input_matrix.get_values()[i][j];

			if (j != COLUMNS_INPUT_MATRIX - 1) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		if (i == row_to_print_text_symbol_scalar) {
			if (!multiply) {
				cout << " " << operation_symbol << " "
					<< scalar << " = ";
			}
			else {
				cout << " = ";
			}
		}
		else if (!multiply) {
			for (int k = 0; k < scalar_length + 6; k++) {
				cout << " ";
			}
		}
		else {
			cout << EMPTY_STRING;
		}

		if (result_matrix.get_values() != NULL) {
			cout << BEGIN_END_ROW_SYMBOL;
			for (int j = 0; j < COLUMNS_INPUT_MATRIX; j++) {
				int column_longest_number =
					result_matrix_longest_elements_lengths
					.get_elements_lengths()[j];

				cout << setw(column_longest_number)
					<< result_matrix.get_values()[i][j];

				if (j != COLUMNS_INPUT_MATRIX - 1) {
					cout << " ";
				}
			}
			cout << BEGIN_END_ROW_SYMBOL << endl;
		}
	}

	input_matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();

	result_matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();
}

void print_matrix_det(MatrixRepresentation matrix,
	double determinant, bool determinant_exists) {

	const char* message = "Determinant of ";
	char BEGIN_END_ROW_SYMBOL = (char)((unsigned int)186);
	const int ROWS_INPUT_MATRIX = matrix
		.get_dimensions().get_rows();

	const int COLUMNS_INPUT_MATRIX = matrix
		.get_dimensions().get_columns();

	LongestElementsLengths matrix_longest_elements_lengths =
		get_columns_longest_elements(
			matrix, COLUMNS_INPUT_MATRIX);

	int row_to_print_det_value = ROWS_INPUT_MATRIX / 2;
	int len = strlen(message);

	for (int i = 0; i < ROWS_INPUT_MATRIX; i++) {
		if (i == row_to_print_det_value) {
			cout << message;
		}
		else {
			for (int k = 0; k < len; k++) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS_INPUT_MATRIX; j++) {
			int column_longest_number = matrix_longest_elements_lengths
				.get_elements_lengths()[j];

			cout << setw(column_longest_number)
				<< matrix.get_values()[i][j];

			if (j != COLUMNS_INPUT_MATRIX - 1) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		if (i == row_to_print_det_value) {
			if (determinant_exists) {
				cout << " = " << determinant;
			}
			else {
				cout << " = NaN";
			}
		}
		cout << endl;
	}

	matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();
}

void print_matrix_inverse_transpose(
	MatrixRepresentation input_matrix,
	MatrixRepresentation result_matrix,
	const char* message,
	bool transpose) {

	print_matrix('A', input_matrix);

	int rows, columns;
	if (transpose) {
		rows = input_matrix
			.get_dimensions().get_columns();

		columns = input_matrix
			.get_dimensions().get_rows();
	}
	else {
		rows = input_matrix
			.get_dimensions().get_rows();

		columns = input_matrix
			.get_dimensions().get_columns();
	}

	LongestElementsLengths result_matrix_longest_elements =
		get_columns_longest_elements(
			result_matrix, columns);

	int message_length = strlen(message);
	int row_to_print_message = rows / 2;
	const char BEGIN_END_ROW_SYMBOL = (char)((unsigned int)186);

	for (int i = 0; i < rows; i++) {
		if (i == row_to_print_message) {
			cout << message;
		}
		else {
			for (int k = 0; k < message_length; k++) {
				cout << " ";
			}
		}

		if (result_matrix.get_values() != NULL) {
			cout << BEGIN_END_ROW_SYMBOL;

			for (int j = 0; j < columns; j++) {
				int column_longest_number =
					result_matrix_longest_elements
					.get_elements_lengths()[j];

				cout << setw(column_longest_number)
					<< result_matrix.get_values()[i][j];

				if (j != columns - 1) {
					cout << " ";
				}
			}

			cout << BEGIN_END_ROW_SYMBOL << endl;
		}
	}
}