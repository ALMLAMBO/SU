/**
*
* Solution to homework assignment 2
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
#include <vector>
#include <iomanip>

using namespace std;

void process_numbers(int cycle_iterations, vector<int>& numbers);

int main() {
	int numbers_count;

	cin >> numbers_count;

	if(!(numbers_count >= 3 && numbers_count <= 100)) {
		cout << "Invalid input data" << endl;
		
		return -1;
	}

	vector<int> numbers;
	
	for (int i = 0; i < numbers_count; i++) {
		int number;
		cin >> number;

		numbers.push_back(number);
	}

	int cycle_iterations = numbers_count / 2;

	if (numbers_count % 2 != 0) {
		cycle_iterations += 1;
	}

	process_numbers(cycle_iterations, numbers);

	return 0;
}

void process_numbers(int cycle_iterations, vector<int>& numbers) {
	bool is_triangle = true;
	
	for (int i = 0; i < cycle_iterations; i++) {
		int left_element_1 = numbers.at(i);
		int left_element_2 = numbers.at(i + 1);
		int right_element_1 = numbers.at(numbers.size() - i - 1);
		int right_element_2 = numbers.at(numbers.size() - i - 2);

		int left_elements_value = abs(left_element_1 - left_element_2);
		int right_elements_value = abs(right_element_1 - right_element_2);

		if (left_elements_value != right_elements_value) {
			is_triangle = false;
			break;
		}
	}

	cout << noboolalpha << is_triangle << endl;
}