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
#include <string>

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
	string number_as_string = to_string(number);

	if (number_as_string.length() == 2 && number % 10 == 0) {
		return 1;
	}

	int last_index_of_non_zero_number = number_as_string
		.find_last_not_of('0');

	return number_as_string
		.substr(last_index_of_non_zero_number + 1)
		.length();
}

int count_decimal_signs(double number) {
	string number_as_string = to_string(number);

	int index_of_decimal_sign = number_as_string
		.find('.');

	int index_of_last_non_zero_number = number_as_string
		.find_last_not_of('0');

	string str = number_as_string
		.substr(index_of_decimal_sign + 1, index_of_last_non_zero_number - 1);

	//return number_as_string
	//	.substr(index_of_decimal_sign + 1, index_of_last_non_zero_number)
	//	.length();

	return str.length();
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