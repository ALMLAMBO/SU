#include <iostream>
#include <string>

using namespace std;

//converting from decimal system
void convert_decimal_to_binary(string input_number_value);
void convert_decimal_to_octal(string input_number_value);
void convert_decimal_to_hex(string input_number_value);

//converting from hexadecimal system
void convert_hex_to_decimal(string input_number_value);
void convert_hex_to_binary(string input_number_value);
void convert_hex_to_octal(string input_number_value);

int main() {
	char input_numeral_system, output_numeral_system;
	string input_number_value;

	cout << "Enter input numeral system: " << endl;
	cin >> input_numeral_system;

	cout << "Enter input number: " << endl;
	cin >> input_number_value;

	cout << "Enter output numeral system: " << endl;
	cin >> output_numeral_system;

	if (input_numeral_system == 'd') {
		if (output_numeral_system == 'b') {
			convert_decimal_to_binary(input_number_value);
		}
		else if (output_numeral_system == 'h') {
			convert_decimal_to_hex(input_number_value);
		}
		else if (output_numeral_system == 'o') {
			convert_decimal_to_octal(input_number_value);
		}
		else {
			cout << "Invalid output numeral system" << endl;
		}
	}
	else if (input_numeral_system == 'h') {
		if (output_numeral_system == 'd') {
			convert_hex_to_decimal(input_number_value);
		}
		else if (output_numeral_system == 'b') {
			convert_hex_to_binary(input_number_value);
		}
		else if (output_numeral_system == 'o') {
			convert_hex_to_octal(input_number_value);
		}
		else {
			cout << "Invalid output numeral system" << endl;
		}
	}
	else {
		cout << "Invalid input numeral system" << endl;
	}

	return 0;
}

void convert_decimal_to_binary(string input_number_value) {
	int converted_number = stoi(input_number_value);
	int current_bit;
	string binary_representation;

	if (converted_number == 0) {
		cout << "Binary representation: 0" << endl;
		return;
	}
	else if (converted_number < 0) {
		binary_representation += '-';
		string binary_positive;

		while (converted_number < 0) {
			current_bit = converted_number % 2;
			char bit_to_add = '0' - current_bit;

			binary_positive += bit_to_add;
			converted_number /= 2;
		}

		reverse(binary_positive.begin(), binary_positive.end());
		binary_representation.append(binary_positive);
	}
	else if (converted_number > 0) {
		while (converted_number > 0) {
			current_bit = converted_number % 2;
			char bit_to_add = '0' + current_bit;

			binary_representation += bit_to_add;
			converted_number /= 2;
		}

		reverse(binary_representation.begin(), binary_representation.end());
	}

	cout << "Binary representation: " << binary_representation << endl;
}

void convert_decimal_to_hex(string input_number_value) {
	int converted_number = stoi(input_number_value);
	int current_bit;
	string hex_representation;

	if (converted_number == 0) {
		cout << "Hex representation: 0" << endl;
		return;
	}
	else if (converted_number < 0) {
		hex_representation += '-';
		string hex_positive;

		while (converted_number < 0) {
			current_bit = converted_number % 16;

			switch (current_bit) {
				case 0: hex_positive += '0'; break;
				case -1: hex_positive += '1'; break;
				case -2: hex_positive += '2'; break;
				case -3: hex_positive += '3'; break;
				case -4: hex_positive += '4'; break;
				case -5: hex_positive += '5'; break;
				case -6: hex_positive += '6'; break;
				case -7: hex_positive += '7'; break;
				case -8: hex_positive += '8'; break;
				case -9: hex_positive += '9'; break;
				case -10: hex_positive += 'A'; break;
				case -11: hex_positive += 'B'; break;
				case -12: hex_positive += 'C'; break;
				case -13: hex_positive += 'D'; break;
				case -14: hex_positive += 'E'; break;
				case -15: hex_positive += 'F'; break;
			}

			converted_number /= 16;
		}

		reverse(hex_positive.begin(), hex_positive.end());
		hex_representation.append(hex_positive);
	}
	else if (converted_number > 0) {
		while (converted_number > 0) {
			current_bit = converted_number % 16;

			switch (current_bit) {
				case 0: hex_representation += '0'; break;
				case 1: hex_representation += '1'; break;
				case 2: hex_representation += '2'; break;
				case 3: hex_representation += '3'; break;
				case 4: hex_representation += '4'; break;
				case 5: hex_representation += '5'; break;
				case 6: hex_representation += '6'; break;
				case 7: hex_representation += '7'; break;
				case 8: hex_representation += '8'; break;
				case 9: hex_representation += '9'; break;
				case 10: hex_representation += 'A'; break;
				case 11: hex_representation += 'B'; break;
				case 12: hex_representation += 'C'; break;
				case 13: hex_representation += 'D'; break;
				case 14: hex_representation += 'E'; break;
				case 15: hex_representation += 'F'; break;
			}

			converted_number /= 16;
		}

		reverse(hex_representation.begin(), hex_representation.end());
	}

	cout << "Hex representation: " << hex_representation << endl;
}

void convert_decimal_to_octal(string input_number_value) {
	int converted_number = stoi(input_number_value);
	int current_bit;
	string octal_representation;

	if (converted_number == 0) {
		cout << "Octal representation: 0" << endl;
		return;
	}
	else if (converted_number < 0) {
		octal_representation += '-';
		string octal_positive;

		while (converted_number < 0) {
			current_bit = converted_number % 8;
			octal_positive += '0' - current_bit;

			converted_number /= 8;
		}

		reverse(octal_positive.begin(), octal_positive.end());
		octal_representation.append(octal_positive);
	}
	else if (converted_number > 0) {
		while (converted_number > 0) {
			current_bit = converted_number % 8;
			octal_representation += '0' + current_bit;

			converted_number /= 8;
		}

		reverse(octal_representation.begin(), octal_representation.end());
	}

	cout << "Octal representation: " << octal_representation << endl;
}

void convert_hex_to_decimal(string input_number_value) {
	reverse(input_number_value.begin(), input_number_value.end());
	
	if (input_number_value == "0") {
		cout << "Decimal representation: 0" << endl;

		return;
	}
	else if (input_number_value.find('-') != string::npos) {
		int decimal_number = 0;

		string positive_hex = input_number_value
			.substr(0, input_number_value.find('-'));

		for (int i = 0; i < positive_hex.size(); i++) {
			switch (positive_hex.at(i)) {
				case '0': break;
				case '1': decimal_number += pow(16, i); break;
				case '2': decimal_number += 2 * pow(16, i); break;
				case '3': decimal_number += 3 * pow(16, i); break;
				case '4': decimal_number += 4 * pow(16, i); break;
				case '5': decimal_number += 5 * pow(16, i); break;
				case '6': decimal_number += 6 * pow(16, i); break;
				case '7': decimal_number += 7 * pow(16, i); break;
				case '8': decimal_number += 8 * pow(16, i); break;
				case 'A': decimal_number += 10 * pow(16, i); break;
				case 'B': decimal_number += 11 * pow(16, i); break;
				case 'C': decimal_number += 12 * pow(16, i); break;
				case 'D': decimal_number += 13 * pow(16, i); break;
				case 'E': decimal_number += 14 * pow(16, i); break;
				case 'F': decimal_number += 15 * pow(16, i); break;
			}
		}

		cout << "Decimal representation: " << -decimal_number << endl;
	}
	else {
		int decimal_number = 0;

		for (int i = 0; i < input_number_value.size(); i++) {
			switch (input_number_value.at(i)) {
				case '0': break;
				case '1': decimal_number += pow(16, i); break;
				case '2': decimal_number += 2 * pow(16, i); break;
				case '3': decimal_number += 3 * pow(16, i); break;
				case '4': decimal_number += 4 * pow(16, i); break;
				case '5': decimal_number += 5 * pow(16, i); break;
				case '6': decimal_number += 6 * pow(16, i); break;
				case '7': decimal_number += 7 * pow(16, i); break;
				case '8': decimal_number += 8 * pow(16, i); break;
				case 'A': decimal_number += 10 * pow(16, i); break;
				case 'B': decimal_number += 11 * pow(16, i); break;
				case 'C': decimal_number += 12 * pow(16, i); break;
				case 'D': decimal_number += 13 * pow(16, i); break;
				case 'E': decimal_number += 14 * pow(16, i); break;
				case 'F': decimal_number += 15 * pow(16, i); break;
			}
		}

		cout << "Decimal representation: " << decimal_number << endl;
	}
}

void convert_hex_to_binary(string input_number_value) {

}

void convert_hex_to_octal(string input_number_value) {

}