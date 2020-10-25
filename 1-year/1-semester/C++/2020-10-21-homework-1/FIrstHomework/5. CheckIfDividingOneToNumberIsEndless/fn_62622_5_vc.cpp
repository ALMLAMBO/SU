/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int count_zeros(int number);
int count_decimal_signs(double number);
bool denominator_is_power_of_ten(int denominator);

int main() {
	const int minimum_required_number = 2;
	const int maximum_required_number = pow(10, 9);

	int input_number;
	int numerator = 1, denominator;

	cin >> input_number;

	int zeros_count = count_zeros(input_number);
	
	if (input_number >= minimum_required_number &&
		input_number <= maximum_required_number) {

		if (input_number < 10000) {

			if (zeros_count == 0) {
				denominator = input_number;
			}
			else {
				denominator = input_number / pow(10, zeros_count);
			}
		}
		else {
			numerator = pow(10, 4);
			denominator = input_number;
		}

		int temp_denominator = denominator;

		while (temp_denominator % 2 == 0) {
			temp_denominator /= 2;
		}

		while (temp_denominator % 5 == 0) {
			temp_denominator /= 5;
		}

		if (temp_denominator != 1) {
			cout << endl << "NO" << endl;
		}
		else {
			double numerator_as_double = numerator;
			double division_result = numerator_as_double / denominator;

			int number_of_decimal_signs =
				count_decimal_signs(division_result);

			int total_number_of_decimal_signs = number_of_decimal_signs;

			if(denominator_is_power_of_ten(denominator)) {
				total_number_of_decimal_signs = zeros_count;
			}
			else {
				if (denominator < 10000) {
					total_number_of_decimal_signs += zeros_count;
				}
				else {
					total_number_of_decimal_signs += zeros_count + 1;
				}
			}

			cout << endl << total_number_of_decimal_signs << endl;
		}
	}
	else {
		cout << endl << "Invalid input data" << endl;
	}

	return 0;
}

int count_zeros(int number) {
	int zeros_count = 0;

	while (number % 10 == 0) {
		zeros_count++;
		number /= 10;
	}

	return zeros_count;
}

int count_decimal_signs(double number) {
	int decimal_signs_count = 0;
	double whole_part;

	//https://www.geeksforgeeks.org/modf-in-cc/
	while (modf(number, &whole_part) != 0) {
		decimal_signs_count++;
		number *= 10;
	}

	return decimal_signs_count;
}

bool denominator_is_power_of_ten(int denominator) {
	if (denominator % 10 != 0) {
		return false;
	}
	
	while (denominator % 10 == 0) {
		if (denominator % 10 != 0) {
			return false;
		}

		denominator /= 10;
	}

	if (denominator != 1) {
		return false;
	}

	return true;
}