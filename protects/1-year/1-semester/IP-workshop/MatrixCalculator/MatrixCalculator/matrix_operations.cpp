#include <iostream>
#include <fstream>
#include <string>
#include "matrix_operations.h"
#include "helper_functions.h"
#include "print_functions.h"

using namespace std;

/// <summary>
/// Multiplies matrix with a number
/// </summary>
void matrix_multiplication_with_number() {
	ifstream matrix_mult_number_file;
	const char* filename = "matrix_mult_number.txt";

	matrix_mult_number_file.open(filename);

	if (!matrix_mult_number_file.is_open()) {
		cout << "File open failed" << endl;
		return;
	}
	else {
		const int MAX_SCALAR_LENGTH = 315;
		char* scalar_as_string = new char[MAX_SCALAR_LENGTH + 2];

		struct matrix_dimensions* sizes =
			get_matrix_dimensions(matrix_mult_number_file);

		struct matrix_representation* matrix =
			new struct matrix_representation[1];

		matrix -> dimensions = sizes;
		matrix -> values = get_matrix_values(
			matrix_mult_number_file, sizes);
	
		matrix_mult_number_file.getline(scalar_as_string, 
			MAX_SCALAR_LENGTH + 2);

		int scalar_length = strlen(scalar_as_string);
		char* first_scalar_number = scalar_as_string + 1;
		char* last_scalar_number = scalar_as_string + scalar_length - 1;

		char* filtered_scalar = new char[MAX_SCALAR_LENGTH];
		filtered_scalar = strstr(first_scalar_number, last_scalar_number);

		double scalar = stof(filtered_scalar);
		const int ROWS = matrix -> dimensions -> rows;
		const int COLUMNS = matrix -> dimensions -> columns;
	
		struct matrix_representation* result_matrix = 
			new struct matrix_representation[1];
		
		result_matrix -> dimensions = matrix -> dimensions;
		result_matrix -> values = new double* [ROWS];

		for (int i = 0; i < ROWS; i++) {
			result_matrix -> values[i] = new double[COLUMNS];
		
			for (int j = 0; j < COLUMNS; j++) {
				result_matrix -> values[i][j] = matrix ->
					values[i][j] * scalar;
			}
		}

		cout << scalar << " * ";
		print_matrix(matrix);
		cout << " = ";
		print_matrix(result_matrix);
	}
}

/// <summary>
/// Multiplies two matrices
/// </summary>
void matrices_multiplication() {

}

/// <summary>
/// Finds matrix determinant using Sarus's rule
/// </summary>
/// <returns>determinant value</returns>
double calculate_matrix_determinant() {
	const char* filename = "matrix_det.txt";
	ifstream matrix_det;
	matrix_det.open(filename);

	double determinant = INT_MIN;

	if (matrix_det.is_open()) {
		struct matrix_dimensions* sizes =
			get_matrix_dimensions(matrix_det);

		struct matrix_representation* matrix =
			new struct matrix_representation[1];

		matrix -> dimensions = sizes;
		const int ROWS = matrix -> dimensions -> rows;
		const int COLUMNS = matrix -> dimensions -> columns;

		if (ROWS == COLUMNS && 
			(ROWS <= 4 && COLUMNS <= 4)) {

			matrix -> values = get_matrix_values(
				matrix_det, matrix -> dimensions);

			double** extended_matrix_values = new double* [ROWS];
			const int EXTENDED_MATRIX_VALUES_COLUMNS = COLUMNS * 2 - 1;
			
			for (int i = 0; i < ROWS; i++) {
				extended_matrix_values[i] = new double[
					EXTENDED_MATRIX_VALUES_COLUMNS];

				for (int j = 0; j < COLUMNS; j++) {
					extended_matrix_values[i][j] = 
						matrix -> values[i][j];
				}

				for (int j = 0; j < COLUMNS - 1; j++) {
					extended_matrix_values[i][COLUMNS + j] =
						matrix -> values[i][j];
				}
			}


		}
	}
}

/// <summary>
/// Divides matrix with number
/// </summary>
void matrix_division_with_number() {
	
}

/// <summary>
/// returns inverse matrix if exists
/// </summary>
/// </returns>
struct matrix_representation * find_matrix_inverse() {

}

/// <summary>
/// Transpose a matrix
/// </summary>
/// <returns> transposed matrix </returns>
struct matrix_representation * matrix_transposition() {
	const char* filename = "matrix-transpose.txt";
	ifstream matrix_transpose;
	matrix_transpose.open(filename);
	struct matrix_representation* transpose = NULL;

	if (matrix_transpose.is_open()) {
		struct matrix_dimensions* sizes =
			get_matrix_dimensions(matrix_transpose);

		struct matrix_representation* matrix =
			new struct matrix_representation[1];

		matrix -> dimensions = sizes;
		matrix -> values = get_matrix_values(
			matrix_transpose, sizes);

		transpose = new struct matrix_representation[1];
		transpose -> dimensions -> rows = 
			matrix -> dimensions -> columns;
	
		transpose -> dimensions -> columns =
			matrix -> dimensions -> rows;

		const int ROWS = transpose -> dimensions -> rows;
		const int COLUMNS = transpose -> dimensions -> columns;

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				transpose -> values[i][j] = matrix -> values[j][i];
			}
		}
	}

	return transpose;
}

void singular_value_decomposition() {

}

//Optional

/// <summary>
/// Sums or substracts two matrices
/// </summary>
/// <param name="sum">true for sum, false for substraction</param>
void matrix_sum_substract(bool sum) {

}

/// <summary>
/// divides two matrices if exsists inverse of second
/// and columns of first matrix equal rows of second matrix
/// </summary>
void matrices_division() {

}