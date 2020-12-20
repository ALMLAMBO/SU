/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int check_possible_concatenation(char * first_string,
	char * second_string, char * expected_string);

int string_length(char* string);
bool contains_all_elements(char* first_string,
	char* second_string, bool duplicates);

bool contains_only_small_letters(char* string);
char* add_element_to_string(char* string);

int main() {
	const int MAX_SIZE = 150;

	char first_string[MAX_SIZE];
	char second_string[MAX_SIZE];
	char third_string[MAX_SIZE];

	cin >> first_string >> second_string >> third_string;

	int result = check_possible_concatenation(first_string,
		second_string, third_string);

	cout << result << endl;

	return 0;
}

int check_possible_concatenation(char* first_string,
	char* second_string, char* expected_string) {

	int result = INT_MIN;
	int length_first_string = string_length(first_string);
	int length_second_string = string_length(second_string);
	int expected_string_length = string_length(expected_string);

	int sum_lengths_first_second_strings =
		length_first_string + length_second_string;

	if (!contains_only_small_letters(first_string) 
		|| !contains_only_small_letters(second_string) 
		|| !contains_only_small_letters(expected_string)) {

		return -1;
	}

	if (contains_all_elements(first_string, expected_string, false) 
		&& contains_all_elements(second_string, expected_string, false)) {
		
		if (sum_lengths_first_second_strings == expected_string_length) {
			result = 1;
		}
		else if (sum_lengths_first_second_strings < expected_string_length) {
			result = -1;
		}
		else if (sum_lengths_first_second_strings > expected_string_length) {
			if (contains_all_elements(first_string,
				second_string, true)) {

				result = 0;
			}
			else {
				result = -1;
			}
		}
	}
	else {
		result = -1;
	}

	return result;
}

int string_length(char* string) {
	int count = 0;
	while (string[count++] != '\0');

	return count - 1;
}

bool contains_all_elements(char* first_string,
	char* second_string, bool duplicates) {

	int length_first_string = string_length(first_string);
	int length_second_string = string_length(second_string);
	int smaller_length = INT_MIN;
	int bigger_length = INT_MAX;
	char* smaller_string = NULL;
	char* bigger_string = NULL;

	if (length_first_string > length_second_string) {
		smaller_length = length_second_string;
		bigger_length = length_second_string;
		smaller_string = second_string;
		bigger_string = first_string;
	}
	else {
		smaller_length = length_first_string;
		bigger_length = length_second_string;
		smaller_string = first_string;
		bigger_string = second_string;
	}

	bool result = false;
	bool stop_cycle = false;

	if (duplicates) {
		for (int i = 0; i < smaller_length; i++) {
			for (int j = 0; j < bigger_length; j++) {
				if (smaller_string[i] == bigger_string[j]) {
					result = true;
				}
			}
		}
	}
	else {
		char* smaller_string_enlarged =
			add_element_to_string(smaller_string);

		char* bigger_string_enlarged =
			add_element_to_string(bigger_string);

		char* last_element_big_enlarged =
			bigger_string_enlarged + bigger_length + 1;

		for (int i = 0; i < smaller_length; i++) {
			if (find(bigger_string_enlarged, last_element_big_enlarged,
				smaller_string[i]) == last_element_big_enlarged) {

				return false;
			}
		}
	}

	return true;
}

bool contains_only_small_letters(char* string) {
	int length = string_length(string);

	for (int i = 0; i < length; i++) {
		if (string[i] < 'a' || string[i] > 'z') {
			return false;
		}
	}

	return true;
}

char* add_element_to_string(char* string) {
	int string_len = string_length(string);
	int new_string_len = string_len + 1;
	char* new_string = new char[new_string_len];

	for (int i = 0; i < string_len; i++) {
		new_string[i] = string[i];
	}

	new_string[new_string_len - 1] = '#';

	return new_string;
}