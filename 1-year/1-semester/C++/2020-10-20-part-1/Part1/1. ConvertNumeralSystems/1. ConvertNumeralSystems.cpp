#include <iostream>
#include <string>

using namespace std;

//converting from decimal system
void convert_decimal_to_binary(string input_number_value);
void convert_decimal_to_octal(string input_number_value);
void convert_decimal_to_hex(string input_number_value);

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