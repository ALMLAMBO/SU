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

void print_smallest_palindrome(int smallest_number,
	int medium_number, int largest_number);

int main() {
	int first_number, second_number, third_number;
	cin >> first_number >> second_number >> third_number;

	if (first_number <= second_number && 
		first_number <= third_number) {

		if (second_number < third_number) {
			print_smallest_palindrome(first_number, 
				second_number, third_number);
		}
		else {
			print_smallest_palindrome(first_number,
				third_number, second_number);
		}
	}
	else if (second_number <= first_number && 
		second_number <= third_number) {

		if (first_number < third_number) {
			print_smallest_palindrome(second_number,
				first_number, third_number);
		}
		else {
			print_smallest_palindrome(second_number,
				third_number, first_number);
		}
	}
	else {
		if (first_number < second_number) {
			print_smallest_palindrome(third_number,
				first_number, second_number);
		}
		else {
			print_smallest_palindrome(third_number,
				second_number, first_number);
		}
	}

	return 0;
}

void print_smallest_palindrome(int smallest_number,
	int medium_number, int largest_number) {

	cout << endl
		<< smallest_number << medium_number
		<< largest_number
		<< medium_number << smallest_number << endl;
}