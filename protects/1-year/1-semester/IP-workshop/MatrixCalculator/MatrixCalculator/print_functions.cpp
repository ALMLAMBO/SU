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

	const char* EMPTY_STRING = "   ";
	const char BEGIN_END_ROW_SYMBOL = (char)186;
	const int ROWS_FIRST_INPUT_MATRIX = first_input_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_FIRST_INPUT_MATRIX = first_input_matrix
		.get_dimensions().get_columns();

	const int ROWS_SECOND_INPUT_MATRIX = second_input_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_SECOND_INPUT_MATRIX = second_input_matrix
		.get_dimensions().get_columns();

	MatrixElementsLength first_input_matrix_elements_lengths =
		get_matrix_elements_lengths(first_input_matrix);

	MatrixElementsLength second_input_matrix_elements_lengths =
		get_matrix_elements_lengths(second_input_matrix);

	MatrixElementsLength result_matrix_elements_lengths =
		get_matrix_elements_lengths(result_matrix);

	LongestElementsLengths first_input_matrix_longest_elements =
		get_columns_longest_elements(
			first_input_matrix_elements_lengths,
			COLUMNS_FIRST_INPUT_MATRIX);

	LongestElementsLengths second_input_matrix_longest_elements =
		get_columns_longest_elements(
			second_input_matrix_elements_lengths,
			COLUMNS_SECOND_INPUT_MATRIX);

	LongestElementsLengths result_matrix_longest_elements =
		get_columns_longest_elements(
			result_matrix_elements_lengths,
			COLUMNS_SECOND_INPUT_MATRIX);

	int row_to_print_matrix_letter = 
		ROWS_FIRST_INPUT_MATRIX / 2;
	
	int row_to_print_second_matrix_letter = 
		ROWS_SECOND_INPUT_MATRIX / 2;
	
	for (int i = 0; i < ROWS_FIRST_INPUT_MATRIX; i++) {
		if (i == row_to_print_matrix_letter) {
			cout << "A = ";
		}
		else {
			cout << EMPTY_STRING;
		}
		
		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS_FIRST_INPUT_MATRIX; j++) {
			int column_longest_number =
				first_input_matrix_longest_elements
				.get_elements_lengths()[j];

			cout << setw(column_longest_number) <<
				first_input_matrix.get_values()[i][j];

			if (j != COLUMNS_FIRST_INPUT_MATRIX - 1) {
				cout << " ";
			}
		}
		cout << BEGIN_END_ROW_SYMBOL << endl;
	}
	cout << endl << endl;

	for (int i = 0; i < ROWS_SECOND_INPUT_MATRIX; i++) {
		if (i == row_to_print_second_matrix_letter) {
			cout << "B = ";
		}
		else {
			cout << EMPTY_STRING;
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS_SECOND_INPUT_MATRIX; j++) {
			int column_longest_number =
				second_input_matrix_longest_elements
				.get_elements_lengths()[j];

			cout << setw(column_longest_number) <<
				second_input_matrix.get_values()[i][j];

			if (j != COLUMNS_SECOND_INPUT_MATRIX - 1) {
				cout << " ";
			}
		}
		cout << BEGIN_END_ROW_SYMBOL << endl;
	}
	cout << endl << endl;

	for (int i = 0; i < ROWS_FIRST_INPUT_MATRIX; i++) {
		if (i == row_to_print_matrix_letter) {
			cout << "A " << operation_symbol << " B = ";
		}
		else {
			for (int i = 0; i < 8; i++) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS_SECOND_INPUT_MATRIX; j++) {
			int column_longest_number =
				result_matrix_longest_elements
				.get_elements_lengths()[j];

			cout << setw(column_longest_number)
				<< result_matrix.get_values()[i][j];
		}
	}
}

void print_matrix_mult_divide_number(
	MatrixRepresentation input_matrix,
	MatrixRepresentation result_matrix,
	char operation_symbol,
	bool multiply,
	double scalar) {

	MatrixElementsLength input_matrix_elements_lengths =
		get_matrix_elements_lengths(input_matrix);

	MatrixElementsLength result_matrix_elements_lengths =
		get_matrix_elements_lengths(result_matrix);

	const char* EMPTY_STRING = "   ";
	const char BEGIN_END_ROW_SYMBOL = (char)186;
	const int ROWS_INPUT_MATRIX = input_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_INPUT_MATRIX = input_matrix
		.get_dimensions().get_columns();

	LongestElementsLengths input_matrix_longest_elements_lengths =
		get_columns_longest_elements(
			input_matrix_elements_lengths,
			COLUMNS_INPUT_MATRIX);

	LongestElementsLengths result_matrix_longest_elements_lengths =
		get_columns_longest_elements(
			result_matrix_elements_lengths,
			COLUMNS_INPUT_MATRIX);

	int row_to_print_text_symbol_scalar = ROWS_INPUT_MATRIX / 2;
	int scalar_length = get_element_length(scalar);

	for (int i = 0; i < ROWS_INPUT_MATRIX; i++) {
		if (i == row_to_print_text_symbol_scalar) {
			if (multiply) {
				cout << scalar << " "
					<< operation_symbol << " ";
			}
		}
		else if(multiply) {
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
	
	input_matrix_elements_lengths.destroy_elements_lengths();
	result_matrix_elements_lengths.destroy_elements_lengths();
	input_matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();

	result_matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();
}

void print_matrix_det(MatrixRepresentation matrix,
	double determinant, bool determinant_exists) {

	MatrixElementsLength matrix_elements_lengths =
		get_matrix_elements_lengths(matrix);
	
	const char* message = "Determinant of ";
	const char BEGIN_END_ROW_SYMBOL = (char)186;
	const int ROWS_INPUT_MATRIX = matrix
		.get_dimensions().get_rows();

	const int COLUMNS_INPUT_MATRIX = matrix
		.get_dimensions().get_columns();

	LongestElementsLengths matrix_longest_elements_lengths =
		get_columns_longest_elements(
			matrix_elements_lengths,
			COLUMNS_INPUT_MATRIX);

	int row_to_print_det_value = ROWS_INPUT_MATRIX / 2;

	for (int i = 0; i < ROWS_INPUT_MATRIX; i++) {
		if (i == row_to_print_det_value) {
			cout << message;
		}
		else {
			for (int k = 0; k < strlen(message); k++) {
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

	matrix_elements_lengths.destroy_elements_lengths();
	matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();
}

void print_matrix_inverse(
	MatrixRepresentation input_matrix,
	MatrixRepresentation inverse_matrix) {

	MatrixElementsLength input_matrix_elements_lengths =
		get_matrix_elements_lengths(input_matrix);

	MatrixElementsLength inverse_matrix_elements_lengths =
		get_matrix_elements_lengths(inverse_matrix);

	const char* message = "Inverse of ";
	const char* EMPTY_STRING = "   ";
	const char BEGIN_END_ROW_SYMBOL = (char)186;
	const int ROWS_INPUT_MATRIX = input_matrix
		.get_dimensions().get_rows();

	const int COLUMNS_INPUT_MATRIX = input_matrix
		.get_dimensions().get_columns();

	LongestElementsLengths input_matrix_longest_elements_lengths =
		get_columns_longest_elements(
			input_matrix_elements_lengths, COLUMNS_INPUT_MATRIX);

	LongestElementsLengths inverse_matrix_longest_elements_lengths =
		get_columns_longest_elements(
			inverse_matrix_elements_lengths, COLUMNS_INPUT_MATRIX);

	int row_to_print_message = ROWS_INPUT_MATRIX / 2;
	bool inverse_matrix_exists = (inverse_matrix.get_values() != NULL);

	for (int i = 0; i < ROWS_INPUT_MATRIX; i++) {
		if (i == row_to_print_message) {
			cout << message;
		}
		else {
			for (int k = 0; k < strlen(message); k++) {
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

		if (i == row_to_print_message) {
			cout << " = ";

			if (!inverse_matrix_exists) {
				cout << "NaN" << endl;
			}
		}
		else {
			cout << EMPTY_STRING;
		}

		if (inverse_matrix_exists) {
			cout << BEGIN_END_ROW_SYMBOL;
			for (int j = 0; j < COLUMNS_INPUT_MATRIX; j++) {
				int inverse_matrix_column_longest_number =
					inverse_matrix_longest_elements_lengths
					.get_elements_lengths()[j];

				cout << setw(inverse_matrix_column_longest_number) <<
					inverse_matrix.get_values()[i][j];
			}
			cout << BEGIN_END_ROW_SYMBOL << endl;
		}
	}

	input_matrix_elements_lengths
		.destroy_elements_lengths();

	inverse_matrix_elements_lengths
		.destroy_elements_lengths();

	input_matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();

	inverse_matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();
}

void print_matrix_transpose(
	MatrixRepresentation matrix,
	MatrixRepresentation result_matrix) {

	MatrixElementsLength matrix_elements_lengths =
		get_matrix_elements_lengths(matrix);

	MatrixElementsLength result_matrix_elements_lengths =
		get_matrix_elements_lengths(result_matrix);

	const char* message = "Transpose of A = ";
	const char* EMPTY_STRING = "   ";
	const char BEGIN_END_ROW_SYMBOL = (char)186;
	const int ROWS_INPUT_MATRIX = matrix
		.get_dimensions().get_rows();

	const int COLUMNS_INPUT_MATRIX = matrix
		.get_dimensions().get_columns();

	LongestElementsLengths matrix_longest_elements_lengths =
		get_columns_longest_elements(
			matrix_elements_lengths,
			COLUMNS_INPUT_MATRIX);

	LongestElementsLengths result_matrix_longest_elements =
		get_columns_longest_elements(
			result_matrix_elements_lengths,
			ROWS_INPUT_MATRIX);

	int row_to_print_message = ROWS_INPUT_MATRIX / 2;

	for (int i = 0; i < ROWS_INPUT_MATRIX; i++) {
		if (i == row_to_print_message) {
			cout << "A = ";
		}
		else {
			for (int i = 0; i < 4; i++) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < COLUMNS_INPUT_MATRIX; j++) {
			int column_longest_number =
				matrix_longest_elements_lengths
				.get_elements_lengths()[j];

			cout << setw(column_longest_number)
				<< matrix.get_values()[i][j];

			if (j != COLUMNS_INPUT_MATRIX - 1) {
				cout << " ";
			}
		}
		cout << BEGIN_END_ROW_SYMBOL << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < COLUMNS_INPUT_MATRIX; i++) {
		if (i == row_to_print_message) {
			cout << message;
		}
		else {
			for (int k = 0; k < strlen(message); k++) {
				cout << " ";
			}
		}

		cout << BEGIN_END_ROW_SYMBOL;
		for (int j = 0; j < ROWS_INPUT_MATRIX; j++) {
			int column_longest_number =
				result_matrix_longest_elements
				.get_elements_lengths()[j];

			cout << setw(column_longest_number)
				<< result_matrix.get_values()[i][j];

			if (j != ROWS_INPUT_MATRIX - 1) {
				cout << " ";
			}
		}
		cout << BEGIN_END_ROW_SYMBOL << endl;
	}

	matrix_elements_lengths
		.destroy_elements_lengths();

	result_matrix_elements_lengths
		.destroy_elements_lengths();

	matrix_longest_elements_lengths
		.destroy_elements_elements_lengths();

	result_matrix_longest_elements
		.destroy_elements_elements_lengths();
}