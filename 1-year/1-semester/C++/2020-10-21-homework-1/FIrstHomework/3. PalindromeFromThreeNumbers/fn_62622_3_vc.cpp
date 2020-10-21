/**
*
* Solution to homework assignment 1
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

string generate_smallest_palindrome(char smallest_number_as_char,
	char medium_number_as_char, char largest_number_as_char);

int main() {
	int first_number, second_number, third_number;
	cin >> first_number >> second_number >> third_number;

	string smallest_number_palindrome;

	char first_number_as_char = '0' + first_number;
	char second_number_as_char = '0' + second_number;
	char third_number_as_char = '0' + third_number;

	if (first_number <= second_number && 
		first_number <= third_number) {

		if (second_number < third_number) {
			smallest_number_palindrome = 
				generate_smallest_palindrome(
					first_number_as_char, second_number_as_char, 
					third_number_as_char
				);
		}
		else {
			smallest_number_palindrome =
				generate_smallest_palindrome(
					first_number_as_char, third_number_as_char,
					second_number_as_char
				);
		}
	}
	else if (second_number <= first_number &&
		second_number <= third_number) {

		if (first_number < third_number) {
			smallest_number_palindrome =
				generate_smallest_palindrome(
					second_number_as_char, first_number_as_char,
					third_number_as_char
				);
		}
		else {
			smallest_number_palindrome =
				generate_smallest_palindrome(
					second_number_as_char, third_number_as_char,
					first_number_as_char
				);
		}
	}
	else {
		if (first_number < second_number) {
			smallest_number_palindrome =
				generate_smallest_palindrome(
					third_number_as_char, first_number_as_char,
					second_number_as_char
				);
		}
		else {
			smallest_number_palindrome =
				generate_smallest_palindrome(
					third_number_as_char, second_number_as_char,
					first_number_as_char
				);
		}
	}

	cout << endl << smallest_number_palindrome << endl;

	return 0;
}

string generate_smallest_palindrome(
	char smallest_number_as_char,
	char medium_number_as_char,
	char largest_number_as_char) {

	string smallest_number_palindrome;

	smallest_number_palindrome += smallest_number_as_char;
	smallest_number_palindrome += medium_number_as_char;
	smallest_number_palindrome += largest_number_as_char;
	smallest_number_palindrome += medium_number_as_char;
	smallest_number_palindrome += smallest_number_as_char;

	return smallest_number_palindrome;
}