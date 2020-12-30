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
/// Finds matrix determinant
/// </summary>
/// <returns>determinant value</returns>
int calculate_matrix_determinant() {

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
/// </returns> transposed matrix
struct matrix_representation * matrix_transposition() {

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