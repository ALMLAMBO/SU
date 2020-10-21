/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <string>

using namespace std;

bool number_is_prime(int input_number);
void find_three_numbers_min_sum_mult_same_number(int input_number);

int main() {
	const int minimum_required_number = 1;
	const int maximum_required_number = pow(10, 9);
	
	int input_number;
	cin >> input_number;

	if (input_number >= minimum_required_number &&
		input_number <= maximum_required_number) {

		if (number_is_prime(input_number)) {
			cout << endl << "Number is prime" << endl;
		}
		else {
			find_three_numbers_min_sum_mult_same_number(input_number);
		}
	}
	else {
		cout << endl << "Invalid input data" << endl;
	}

	return 0;
}

bool number_is_prime(int input_number) {
	if (input_number == 1) {
		return true;
	}

	for (int i = 2; i < input_number; i++) {
		if (input_number % i == 0) {
			return false;
		}
	}

	return true;
}

void find_three_numbers_min_sum_mult_same_number(int input_number) {
	int first_number = 0, second_number = 0, third_number = 0;
	int temp_first_number = 0, temp_second_number = 0, temp_third_number = 0;
	int min_sum = INT_MAX;

	for (int i = 1; i <= input_number / 2; i++) {
		int temp_sum;

		if (input_number % i == 0) {
			temp_first_number = i;

			for (int j = i + 1; j <= input_number / i; j++) {
				if (input_number % j == 0) {
					temp_second_number = j;

					temp_third_number = input_number /
						(temp_first_number * temp_second_number);

					temp_sum = temp_first_number
						+ temp_second_number + temp_third_number;

					if (temp_sum < min_sum) {
						min_sum = temp_sum;
						first_number = temp_first_number;
						second_number = temp_second_number;
						third_number = temp_third_number;
					}
				}
			}
		}
	}

	cout << endl << first_number << " " << second_number
		<< " " << third_number << endl;
}