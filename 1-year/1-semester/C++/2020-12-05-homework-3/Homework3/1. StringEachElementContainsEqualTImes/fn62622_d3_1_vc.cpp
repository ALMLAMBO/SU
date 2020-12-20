/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*
*/


#include <iostream>
#include <algorithm>

using namespace std;
bool each_elem_contains_equal(char* string);
bool all_elements_equal(int* arr, int length);
int get_unique_symbols_count(char* string);
int string_length(char* string);

int main() {
	char string[150];
	cin >> string;

	bool contains_equal = each_elem_contains_equal(string);
	cout << noboolalpha << contains_equal << endl;

	return 0;
}

bool each_elem_contains_equal(char* string) {
	int length = string_length(string);
	char* last_element = string + length;
	sort(string, last_element);
	
	int unique_symbols = get_unique_symbols_count(string);
	int* symbols_count = new int[unique_symbols];
	int symbols_count_length = 0;

	int count = 1;
	for (int i = 0; i < length - 1; i++) {
		if (string[i] == string[i + 1]) {
			count++;
		}
		else {
			symbols_count[symbols_count_length++] = count;
			count = 1;
		}
	}

	sort(symbols_count, symbols_count + symbols_count_length);
	bool all_equal = all_elements_equal(
		symbols_count, symbols_count_length);

	bool equal = false;
	if (!all_equal) {
		for (int i = 0; i < symbols_count_length; i++) {
			int count = symbols_count[i];
			count--;

			symbols_count[i] = count;
			if (all_elements_equal(symbols_count, symbols_count_length)) {
				equal = true;
				break;
			}
		}
	}
	else {
		equal = true;
	}

	return equal;
}

bool all_elements_equal(int* arr, int length) {
	int* last_element = arr + length;
	sort(arr, last_element);

	for (int i = 0; i < length - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			return false;
		}
	}

	return true;
}

int get_unique_symbols_count(char* string) {
	int length = string_length(string);

	char* last_element = string + length;
	sort(string, last_element);

	int unique_symbols = 0;
	for (int i = 0; i < length - 1; i++) {
		if (string[i] != string[i + 1]) {
			unique_symbols++;
		}
	}

	return unique_symbols;
}

int string_length(char* string) {
	int count = 0;
	while (string[count++] != '\0');

	return count - 1;
}