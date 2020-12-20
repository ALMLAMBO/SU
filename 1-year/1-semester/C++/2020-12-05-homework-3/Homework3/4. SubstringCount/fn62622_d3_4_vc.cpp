/**
*
* Solution to homework assignment 3
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
#include <algorithm>

using namespace std;

int count_substrings(char* string);
int compare_strings(char* str1, char* str2);
int string_length(char* string);
int string_length(char const* string);
int get_unique_letters_count(char* string);
char* get_substring(char* string, int begin_index, 
	int end_index, int removed_letters);

char* convert_const_to_normal(char const* string);
bool contains_only_letters(char* string);

int main() {
	char* string = new char[100];

	cin >> string;

	int substrings_count = count_substrings(string);

	cout << substrings_count << endl;

	return 0;
}

int count_substrings(char* string) {
	int count = 1;
	int length = strlen(string);

	if (length == 1) {
		return 1;
	}

	if (length == 2) {
		for (int i = 0; i < 1; i++) {
			if (string[i] == string[i + 1]) {
				return 2;
			}
		}

		return 3;
	}

	if (!contains_only_letters(string)) {
		return 0;
	}

	int max_letters_to_be_removed = length - 1;
	int max_substrings = length * length * (length - 1);
	char** substrings = new char* [max_substrings];
	int sub_count = 0;

	count += get_unique_letters_count(string);

	for (int j = 1; j <= max_letters_to_be_removed - 1; j++) {
		for (int i = 0; i < length; i++) {
			char* substring = get_substring(string, 
				length - i - j, length - i, j);

			substrings[sub_count++] = substring;
		}
	}
	
	//https://stackoverflow.com/questions/20931669/sort-a-2d-array-in-c-using-built-in-functionsor-any-other-method
	qsort(substrings, sub_count, sizeof(*substrings),
		[](const void* arg1, const void* arg2) -> int {

			char const* str1_const = static_cast<char const*>(arg1);
			char const* str2_const = static_cast<char const*>(arg2);
			char* str1 = convert_const_to_normal(str1_const);
			char* str2 = convert_const_to_normal(str2_const);

			return compare_strings(str1, str2);
	});

	for (int i = 0; i < sub_count - 1; i++) {
		if (compare_strings(substrings[i], 
			substrings[i + 1]) == 0) {
			
			count++;
		}
	}

	return count;
}

int compare_strings(char* str1, char* str2) {
	int len_str1 = string_length(str1);
	int len_str2 = string_length(str2);

	if (len_str1 > len_str2) {
		return 1;
	}
	else if (len_str1 < len_str2) {
		return -1;
	}

	for (int i = 0; i < len_str1; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}
	}
	
	return 0;
}

int string_length(char* string) {
	int count = 0;
	while (string[count++] != '\0');

	return count - 1;
}

int string_length(char const* string) {
	int count = 0;
	while (string[count++] != '\0');

	return count - 1;
}

int get_unique_letters_count(char* string) {
	int count = 0;
	int length = string_length(string);
	sort(string, string + length);

	for (int i = 0; i < length - 1; i++) {
		if (string[i] != string[i + 1]) {
			count++;
		}
	}

	count++;

	return count;
}

char* get_substring(char* string, int begin_index,
	int end_index, int removed_letters) {

	int string_len = string_length(string);
	int substring_length = string_len - removed_letters;
	char* substring = new char[substring_length + 1];
	int index = 0;

	for (int i = 0; i < string_len; i++) {
		if (i < begin_index || i > end_index) {
			substring[index++] = string[i];
		}
	}

	substring[index] = '\0';

	return substring;
}

char* convert_const_to_normal(char const* string) {
	int length = string_length(string);
	char* result_string = new char[length];

	for (int i = 0; i < length; i++) {
		result_string[i] = string[i];
	}

	return result_string;
}

bool contains_only_letters(char* string) {
	int length = strlen(string);

	for (int i = 0; i < length; i++) {
		if ((string[i] < 65 || string[i] > 90) &&
			(string[i] < 97 || string[i] > 122)) {

			return false;
		}
	}

	return true;
}