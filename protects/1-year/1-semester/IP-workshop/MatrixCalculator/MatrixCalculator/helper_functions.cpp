#include <iostream>
#include <fstream>
#include <string>
#include "helper_functions.h"
#include "matrix_operations.h"

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
		int right = number / 2 + 1;

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
/// <returns>reference to matrix dimensions structure with dimensions set</returns>
MatrixDimensions& get_matrix_dimensions(ifstream& file) {
	MatrixDimensions dimensions;
	const int MAX_DIMENSION_LENGTH = 12;
	const int CYCLE_ITERATIONS = 2;
	bool set_row = false;

	for (int i = 0; i < CYCLE_ITERATIONS; i++) {
		char* dimension_as_string = new char[MAX_DIMENSION_LENGTH];
		file.getline(dimension_as_string, MAX_DIMENSION_LENGTH);
		
		int dimension_length = strlen(dimension_as_string);
		char* first_number_of_dimension = dimension_as_string + 1;
		char* filtered_dimension_as_string = 
			new char[MAX_DIMENSION_LENGTH - 2];

		strncpy(filtered_dimension_as_string, 
			first_number_of_dimension, dimension_length - 2);

		int dimension = stoi(filtered_dimension_as_string);
		
		if (set_row) {
			dimensions.set_rows(dimension);
		}
		else {
			dimensions.set_columns(dimension);
		}
	}

	return dimensions;
}