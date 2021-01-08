#include <iostream>
#include <fstream>
#include <string>
#include "helper_functions.h"
#include "matrix_operations.h"
#include "print_functions.h"

using namespace std;

/// <summary>
/// Calculates square root of number
/// </summary>
/// <param name="number">Input number</param>
/// <returns>square root</returns>
double calclulate_sqrt(double number) {
	double sqrt_number = 0;

	if (number < 0) {
		cout << "Invalid number" << endl;
		sqrt_number = number;
	}
	else if (number == 0) {
		sqrt_number = 0;
	}
	else if (number == 1) {
		sqrt_number = 1;
	}
	else {
		//https://stackoverflow.com/questions/33299667/program-to-calculate-square-root-c
		//First answer second algorithm
		int left = 1;
		int right = (int)(number / 2 + 1);

		while (left <= right) {
			int mid = left + ((right - left) / 2);
			if (mid <= number / mid) {
				left = mid + 1;
				sqrt_number = mid;
			}
			else {
				right = mid - 1;
			}
		}
	}

	return sqrt_number;
}

/// <summary>
/// pows number with exponent
/// </summary>
/// <param name="number">input number</param>
/// <param name="exponent">input exponent</param>
/// <returns>result after power</returns>
double pow_number(double number, int exponent) {
	double powered_number = 1;
	
	if (exponent == 0) {
		powered_number = 1;
	}
	else if (exponent > 0) {
		for (int i = 0; i < exponent; i++) {
			powered_number *= number;
		}
	}
	else if (exponent < 0) {
		for (int i = exponent; i < 0; i++) {
			powered_number *= 1 / number;
		}
	}

	return powered_number;
}

/// <summary>
/// Gets absolute value of number
/// </summary>
/// <param name="number">input number</param>
/// <returns>absolute value</returns>
double absolute_value(double number) {
	double result = 0;
	
	if (number < 0) {
		result = -number;
	}
	
	return result;
}

/// <summary>
/// Get matrix rows and columns counts
/// </summary>
/// <param name="file">reference input file stream to read</param>
/// <returns>matrix dimensions structure with dimensions set</returns>
MatrixDimensions get_matrix_dimensions(std::ifstream& file) {
	MatrixDimensions dimensions;
	const int MAX_DIMENSION_LENGTH = 12;
	const int CYCLE_ITERATIONS = 2;
	bool set_row = true;

	for (int i = 0; i < CYCLE_ITERATIONS; i++) {
		char* dimension_as_string = new char[MAX_DIMENSION_LENGTH];
		file.getline(dimension_as_string, MAX_DIMENSION_LENGTH);

		int dimension = stoi(dimension_as_string);
		
		if (set_row) {
			dimensions.set_rows(dimension);
			set_row = false;
		}
		else {
			dimensions.set_columns(dimension);
		}
	}

	return dimensions;
}

double** get_matrix_values(std::ifstream& file,
	MatrixDimensions dimensions) {

	const int ROWS = dimensions.get_rows();
	const int COLUMNS = dimensions.get_columns();
	const int MAX_NUMBER_LENGTH = 320;

	double** matrix_values = new double* [ROWS];
	
	for (int i = 0; i < ROWS; i++) {
		matrix_values[i] = new double[COLUMNS];
	}

	for (int i = 0; i < ROWS; i++) {
		streamoff line_length = file.tellg() * 2;
		char* line_content = new char[(unsigned int)line_length];
		file.getline(line_content, line_length);
		int column = 0;

		for (int i = 0; i < line_length; i++) {
			char* number_as_string = new char[MAX_NUMBER_LENGTH];
			char symbol = line_content[i];

			int number_length = 0;
			while (symbol != (char)32) {
				if ((symbol >= '0' && symbol <= '9')
					|| symbol == '.') {

					number_as_string[number_length++] = symbol;
					symbol = line_content[++i];
				}
			}

			number_as_string[number_length] = '\0';
			double number = stof(number_as_string);
			matrix_values[i][column++] = number;

			delete[] number_as_string;
			number_as_string = NULL;
		}
	}

	return matrix_values;
}

/// <summary>
/// Initialises matrix representation variable
/// </summary>
/// <param name="file">file stream to read</param>
/// <returns>matrix with values and dimensions set</returns>
MatrixRepresentation get_matrix(const char * filename) {
	ifstream file;
	file.open(filename);
	MatrixRepresentation matrix;

	if (file.is_open()) {
		MatrixDimensions dimensions = get_matrix_dimensions(file);
		matrix.set_dimensions(dimensions);
		matrix.init_empty_matrix_values();

		double** values = get_matrix_values(file, dimensions);
		matrix.set_values(values);

		print_matrix(matrix);
	}

	return matrix;
}

double get_scalar(const char * filename) {
	ifstream file(filename);
	double scalar = 0;
	
	if (file.is_open()) {
		file.seekg(0, ios_base::end);
		streamoff scalar_length = file.tellg();

		char* scalar_as_string = new char[(unsigned int)scalar_length];
		file.getline(scalar_as_string, scalar_length);

		double scalar = stof(scalar_as_string);
		delete[] scalar_as_string;
		scalar_as_string = NULL;
	}

	return scalar;
}