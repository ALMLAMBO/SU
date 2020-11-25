/**
*
* Solution to homework assignment 2
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
#include <vector>

using namespace std;

bool is_palindrome(vector<int>& numbers_to_check);
void process_numbers(vector<int>& numbers);

int main() {
	const int minimum_numbers_count = 3;
	const int maximum_numbers_count = 1000;
	int numbers_count;
	cin >> numbers_count;

	if (numbers_count < minimum_numbers_count 
		|| numbers_count > maximum_numbers_count) {

		cout << "Invalid data" << endl;

		while (numbers_count < minimum_numbers_count
			|| numbers_count > maximum_numbers_count) {
			
			cin >> numbers_count;
		}
	}

	vector<int> numbers;

	for (int i = 0; i < numbers_count; i++) {
		int number;
		cin >> number;

		numbers.push_back(number);
	}

	process_numbers(numbers);

	return 0;
}

/// <summary>
/// checks if number sequence is palindrome
/// </summary>
/// <param name="numbers_to_check">vector with numbers</param>
/// <returns>true if it is or false if it is not</returns>
bool is_palindrome(vector<int>& numbers_to_check) {
	int numbers_to_check_count = numbers_to_check.size();

	for (int i = 0; i < numbers_to_check.size() / 2; i++) {
		int left_element = numbers_to_check.at(i);
		int right_element = numbers_to_check
			.at(numbers_to_check_count - i - 1);

		if (left_element != right_element) {
			return false;
		}
	}

	return true;
}

/// <summary>
/// finds all palindromes in given number sequence
/// </summary>
/// <param name="numbers">numbers to find palindromes</param>
void process_numbers(vector<int>& numbers) {
	int palindromes_count = 0;
	int min_palindrome_len = 3;
	int numbers_count = numbers.size();

	for (int palindrome_length = min_palindrome_len;
		palindrome_length <= numbers_count; palindrome_length++) {

		for (int i = 0; i < numbers_count; i++) {
			if (i + palindrome_length <= numbers_count) {
				//https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector
				//first answer
				vector<int> numbers_to_check(
					numbers.begin() + i,
					numbers.begin() + i + palindrome_length);

				if (is_palindrome(numbers_to_check)) {
					palindromes_count++;
				}
			}
		}
	}

	if (palindromes_count == 0) {
		cout << -1 << endl;
	}
	else {
		cout << palindromes_count << endl;
	}
}