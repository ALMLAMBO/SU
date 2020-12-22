#include <iostream>
#include "helper_functions.h"

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
/// Get matrix with values
/// </summary>
/// <param name="file">reference to input file stream</param>
/// <param name="sizes">dimensions of the matrix</param>
/// <returns>matrix with values</returns>
double** get_matrix_values(ifstream& file,
	struct matrix_dimensions sizes) {


}

/// <summary>
/// Gets length of number
/// </summary>
/// <param name="number">input number</param>
/// <returns>how long it is</returns>
int find_number_length(double number) {
	int length = 0;

	while (number > 0) {
		length++;
		number /= 10;
	}

	int whole_part = (int)number;
	double decimal_part = number - whole_part;

	while (decimal_part != 0) {
		length++;
		decimal_part = (number - whole_part) * 10;
	}

	return length;
}

/// <summary>
/// Gets matrix dimensions
/// </summary>
/// <param name="file">reference input file stream</param>
/// <returns>struct with matrix sizes</returns>
struct matrix_dimensions get_matrix_dimensions(
	ifstream& file) {


}

/// <summary>
/// Gets matrix elements length
/// </summary>
/// <param name="matrix">struct with matrix values and dimensions</param>
/// </returns>struct with matrix elements length<returns>
struct matrix_elements_length get_matrix_elements_length(
	struct matrix_representation matrix) {


}

/// <summary>
/// Gets longest number
/// </summary>
/// <param name="elements">matrix elements length</param>
/// <returns></returns>
int get_longest_number_length(
	struct matrix_elements_length elements) {


}