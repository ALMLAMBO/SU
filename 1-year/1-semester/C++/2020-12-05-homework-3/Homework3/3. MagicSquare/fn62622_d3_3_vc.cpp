/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

bool is_magic_square(int square_size);
double** create_square_matrix(int square_size);
int validate_square_size(int square_size);
double sum_matrix_row_column(double** matrix, int size,
	int row_col, bool column);

double sum_matrix_diagonals(double** matrix, int size, bool main);

int main() {
	int square_size = 0;
	cin >> square_size;

	square_size = validate_square_size(square_size);
	bool magic_square = is_magic_square(square_size);
	cout << endl << boolalpha << magic_square;

	return 0;
}

int validate_square_size(int square_size) {
	int size = square_size;
	
	if (square_size < 1 || square_size > 1000) {
		cout << "Invalid square size" << endl;

		while (square_size < 1 || square_size > 1000) {
			cin >> size;
		}
	}

	return size;
}

bool is_magic_square(int square_size) {
	double** matrix = create_square_matrix(square_size);

	double sum_main_diag = sum_matrix_diagonals(
		matrix, square_size, true);

	double sum_second_diag = sum_matrix_diagonals(
		matrix, square_size, false);

	if (sum_main_diag != sum_second_diag) {
		return false;
	}

	for (int i = 0; i < square_size; i++) {
		double sum_row = sum_matrix_row_column(matrix,
			square_size, i, false);

		double sum_column = sum_matrix_row_column(matrix,
			square_size, i, true);

		if (sum_row != sum_column) {
			return false;
		}
		else if (sum_row != sum_main_diag 
			|| sum_column != sum_main_diag) {
			
			return false;
		}
	}

	return true;
}

double** create_square_matrix(int square_size) {
	double** matrix = new double* [square_size];
	double number = 0;

	for (int i = 0; i < square_size; i++) {
		matrix[i] = new double[square_size];

		for (int j = 0; j < square_size; j++) {
			cin >> number;

			if (number < 0 || number > 100) {
				cout << "Invalid number" << endl;

				while (number < 0 || number > 100) {
					cin >> number;
				}
			}

			matrix[i][j] = number;
		}
	}

	return matrix;
}

double sum_matrix_row_column(double** matrix, 
	int size, int row_col, bool column) {
	
	double sum = 0;

	if (column) {
		for (int i = 0; i < size; i++) {
			sum += matrix[i][row_col];
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			sum += matrix[row_col][i];
		}
	}

	return sum;
}

double sum_matrix_diagonals(double** matrix, int size, bool main) {
	double sum = 0;

	if (main) {
		for (int i = 0; i < size; i++) {
			sum += matrix[i][i];
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			sum += matrix[size - i - 1][i];
		}
	}

	return sum;
}