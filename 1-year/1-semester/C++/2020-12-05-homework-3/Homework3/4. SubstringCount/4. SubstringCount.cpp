#include <iostream>

using namespace std;

int count_substrings(char* string);
bool compare_strings(char* str1, char* str2);
char* get_substring(char* string, int begin_index,
	int end_index, int removed_letters);

bool contains_only_letters(char* string);
int factorial(int number);

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

	int len = factorial(length);
	char** all_substrings = new char* [len];
	int index = 0;

	for (int j = 1; j <= max_letters_to_be_removed; j++) {
		for (int i = 0; i < length; i++) {
			char* str1 = get_substring(string, i, i + j, j);
			all_substrings[index] = str1;

			index++;
		}
	}

	for (int i = 0; i < index - 1; i++) {
		char* str1 = all_substrings[i];
		char* str2 = all_substrings[i + 1];

		int len1 = strlen(all_substrings[i]);
		int len2 = strlen(all_substrings[i + 1]);
		bool equal = true;

		if (len1 > len2 || len2 > len1) {
			count++;
		}
		else if (len1 == len2) {
			for (int j = 0; j < len1; j++) {
				if (str1[j] != str2[j]) {
					equal = false;
					break;
				}
			}
		}

		if (!equal) {
			count++;
		}
	}

	return count;
}

bool compare_strings(char* str1, char* str2) {
	if (str1 == NULL || str2 == NULL) {
		return false;
	}

	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);

	if (len_str1 != len_str2) {
		return false;
	}


	for (int i = 0; i < len_str1; i++) {
		if (str1[i] != str2[i]) {
			return false;
		}
	}

	return true;
}

char* get_substring(char* string, int begin_index,
	int end_index, int removed_letters) {

	int substring_len = strlen(string) - removed_letters;
	char* substring = new char[substring_len + 1];
	int index = 0;

	for (int i = 0; i < strlen(string); i++) {
		if (i < begin_index || i >= end_index) {
			substring[index] = string[i];
			index++;
		}
	}

	index++;
	substring[index] = '\0';

	return substring;
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

int factorial(int number) {
	int result = 1;

	for (int i = 2; i <= number; i++) {
		result *= i;
	}

	return result;
}