#include <iostream>
#include <fstream>
#include <string>
#include "helper_functions.h"
#include "matrix_operations.h"
#include "print_functions.h"
#include <algorithm>

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
		int CYCLE_ITERATIONS = line_length / 2;

		for (int j = 0; i < CYCLE_ITERATIONS; j++) {
			char* number_as_string = new char[MAX_NUMBER_LENGTH];
			char symbol = line_content[j];

			int number_length = 0;
			while (symbol != (char)32) {
				if ((symbol >= '0' && symbol <= '9')
					|| symbol == '.') {

					number_as_string[number_length++] = symbol;
					symbol = line_content[++j];
				}
				else if (symbol == '\0') {
					break;
				}
				else {
					break;
				}
			}

			if (number_length != 0) {
				number_as_string[number_length] = '\0';
				double number = stof(number_as_string);
				matrix_values[i][column] = number;
				column++;
			}

			delete[] number_as_string;
			number_as_string = NULL;

			if (j > CYCLE_ITERATIONS) {
				break;
			}
		}

		delete[] line_content;
		line_content = NULL;
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

		file.close();
	}

	return matrix;
}

/// <summary>
/// Gets scalar for mult or divide matrix with number
/// </summary>
/// <param name="filename">File to get scalar from</param>
/// <returns>scalar</returns>
double get_scalar(const char * filename) {
	ifstream file(filename);
	double scalar = 0;
	
	if (file.is_open()) {
		const int MAX_SCALAR_LENGTH = 320;
		char* scalar_as_string = new char[MAX_SCALAR_LENGTH];
		file.seekg(-1, ios_base::end);

		while (true) {
			char symbol;
			file.get(symbol);

			if (file.tellg() <= 1) {
				file.seekg(0);
				break;
			}
			else if (symbol == '\n') {
				break;
			}
			else {
				file.seekg(-2, ios_base::cur);
			}
		}
		
		file.getline(scalar_as_string, MAX_SCALAR_LENGTH);
		scalar = stof(scalar_as_string);

		file.close();
	}

	return scalar;
}

/// <summary>
/// Gets number length
/// </summary>
/// <param name="number">input number</param>
/// <returns>number length</returns>
int get_element_length(double number) {
	int whole_part = (int)number;
	if (whole_part > number) {
		whole_part--;
	}

	double decimal_part = number - whole_part;
	int length = 0;

	while (whole_part > 0) {
		length++;
		whole_part /= 10;
	}

	if (decimal_part != 0) {
		length++;
	}

	if (number < 0) {
		length++;
	}

	double temp_number;
	int temp_whole_part;
	while (decimal_part != 0) {
		temp_number = decimal_part * 10;
		temp_whole_part = (int)temp_number;
		if (temp_whole_part > temp_number) {
			temp_whole_part--;
		}

		decimal_part = temp_number - temp_whole_part;
		length++;
	}

	return length;
}

/// <summary>
/// Get length of every matrix element
/// </summary>
/// <param name="matrix">input matrix</param>
/// <returns>matrix elements lengths with elements count</returns>
MatrixElementsLength get_matrix_elements_lengths(
	MatrixRepresentation matrix) {

	const int ROWS = matrix.get_dimensions().get_rows();
	const int COLUMNS = matrix.get_dimensions().get_columns();

	MatrixElementsLength elements_lengths;
	if (matrix.get_values() != NULL) {
		const int ELEMENTS_COUNT = ROWS * COLUMNS;
		elements_lengths.set_elements_count(ELEMENTS_COUNT);
		elements_lengths.init_elements_lengths();
		int* elements_length = new int[ELEMENTS_COUNT];

		int count = 0;
		for (int i = 0; i < COLUMNS; i++) {
			for (int j = 0; j < ROWS; j++) {
				elements_length[count++] =
					get_element_length(matrix.get_values()[j][i]);
			}
		}
		elements_lengths.set_elements_lengths(elements_length);

		delete[] elements_length;
		elements_length = NULL;
	}
	else {
		return elements_lengths;
	}

	return elements_lengths;
}

/// <summary>
/// 
/// </summary>
/// <param name="matrix_elements_lengths"></param>
/// <param name="columns"></param>
/// <returns></returns>
LongestElementsLengths get_columns_longest_elements(
	MatrixElementsLength matrix_elements_lengths,
	int columns) {

	LongestElementsLengths elements_lengths;
	if (matrix_elements_lengths
		.get_elements_lengths() != NULL) {
		
		int* longest_elements_lengths = new int[columns];
		elements_lengths.set_elements_count(columns);
		elements_lengths.init_elements_lengths();

		for (int i = 0; i < columns; i++) {
			int* column_begin = matrix_elements_lengths
				.get_elements_lengths() + i * columns;

			int* column_end = matrix_elements_lengths
				.get_elements_lengths() + ((i + 1) * columns);

			int longest_number = *max_element(
				column_begin, column_end);

			longest_elements_lengths[i] = longest_number;
		}

		elements_lengths.set_elements_lengths(
			longest_elements_lengths);

		delete[] longest_elements_lengths;
		longest_elements_lengths = NULL;
	}

	return elements_lengths;
}