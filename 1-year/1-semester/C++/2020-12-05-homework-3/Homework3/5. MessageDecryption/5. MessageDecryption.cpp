#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int find_message_length(const char* filename);
int string_length(char* string);
char* decrypt_message(const char* filename);
void print_message(char* message);
char get_smallest_letter_ascii(char* line);
bool contains_all_small_and_big_letters(char* line);

int main() {
	const char* filename = "message.txt";

	char* decrypted_message = decrypt_message(filename);

	print_message(decrypted_message);
	return 0;
}

int find_message_length(const char* filename) {
	const char NEWLINE_SYMBOL = '\n';
	
	ifstream file;
	file.open(filename);

	int lines_count = 0;

	if (file.fail()) {
		cout << -2 << endl;
		return -2;
	}
	else {
		while (!file.eof()) {
			char symbol = file.get();
			if (symbol == NEWLINE_SYMBOL) {
				lines_count++;
			}
		}
	}

	return lines_count + 1;
}

int string_length(char* string) {
	int count = 0;
	while (string[count++] != '\0');

	return count - 1;
}

char* decrypt_message(const char* filename) {
	int lines_count = find_message_length(filename);
	char* message = (char*)malloc((lines_count + 1) * sizeof(char));

	ifstream file;
	file.open(filename, ios::in);

	if (lines_count < 0) {
		return NULL;
	}

	if (file.fail()) {
		cout << -2 << endl;
		return NULL;
	}
	else {
		int count = 0;

		while (!file.eof()) {
			char line[150];
			file.getline(line, 150);

			char letter = get_smallest_letter_ascii(line);
			message[count] = letter;

			count++;
		}

		message[lines_count] = '\0';
	}

	return message;
}

void print_message(char* message) {
	int length = string_length(message);
	
	for (int i = 0; i < length; i++) {
		if (message[i] != ' ') {
			cout << message[i];
		}
	}

	cout << endl;
}

char get_smallest_letter_ascii(char* line) {
	int line_length = string_length(line);
	
	char* last_element = (line + line_length);
	char smallest_letter_ascii = *min_element(
		line, last_element);

	if (smallest_letter_ascii == 'z') {
		return ' ';
	}

	sort(line, last_element);

	char symbol = '\0';

	if (contains_all_small_and_big_letters(line)) {
		symbol = '.';
	}
	else {
		bool stop_cycle = false;

		for (char letter = smallest_letter_ascii + 1; letter <= 'z'; letter++) {
			for (int i = 1; i < line_length; i++) {
				if (line[i] - line[i - 1] > 1
					&& (line[i] <= 90 || line[i] >= 97)) {

					char c;
					
					if (line[i - 1] == 'Z' 
						&& line[i] - line[i - 1] > 6) {
						//c = line[i] + 4;
						char* p = &line[i];

						c = line[i] + last_element - p;
					}
					else {
						c = ++line[i - 1];
					}

					symbol = c;
					stop_cycle = true;
					break;
				}
			}

			if (stop_cycle) {
				break;
			}
		}
	}

	return symbol;
}

bool contains_all_small_and_big_letters(char* line) {
	//TODO: implement my string_length
	int length = string_length(line);
	char small_letter = 'a';
	char big_letter = 'A';
	char* last_element = line + length - 1;

	while (true) {
		if (find(line, last_element, small_letter)
			== last_element) {

			return false;
		}
		else if (find(line, last_element, big_letter)
			== last_element) {

			return false;
		}

		small_letter++;
		big_letter++;
	}

	return true;
}