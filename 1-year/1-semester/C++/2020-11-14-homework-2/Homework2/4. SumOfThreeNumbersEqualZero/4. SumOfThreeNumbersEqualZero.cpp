/**
*
* Solution to homework assignment 2
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
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_unique_numbers(int unique_numbers_count);
vector<int> get_negative_numbers(vector<int>& unique_numbers);
vector<int> get_non_negative_numbers(vector<int>& unique_numbers);
bool non_negative_numbers_only_zeros(vector<int>& non_negative_numbers);

int find_sum_zero_opposite_elements(
	vector<int>& negative_numbers, 
	vector<int>& non_negative_numbers);

int find_sum_zero_sum_of_two_opposite(
	vector<int>& negative_numbers,
	vector<int>& non_negative_numbers,
	bool positive_first);

void find_three_numbers_sum_zero(
	vector<int>& unique_negative_numbers,
	vector<int>& unique_non_negative_numbers);

int main() {
	int unique_numbers_count;

	cin >> unique_numbers_count;

	if (unique_numbers_count < 3 || unique_numbers_count > 100) {
		cout << "Invalid data" << endl;

		return -1;
	}

	vector<int> unique_numbers = get_unique_numbers(unique_numbers_count);
	vector<int> unique_negative_numbers =
		get_negative_numbers(unique_numbers);
	
	if (unique_negative_numbers.size() == 0) {
		cout << "0" << endl;

		return 0;
	}
	else {
		vector<int> unique_non_negative_numbers =
			get_non_negative_numbers(unique_numbers);

		if (unique_non_negative_numbers.size() == 0) {
			cout << "0" << endl;

			return 0;
		}
		else {
			find_three_numbers_sum_zero(
				unique_negative_numbers,
				unique_non_negative_numbers);
		}
	}

	return 0;
}

/// <summary>
/// get only unique numbers from entered one
/// </summary>
/// <param name="unique_numbers_count">how many should be the unique numbers</param>
/// <returns>int vector with all unique numbers inside of it</returns>
vector<int> get_unique_numbers(int unique_numbers_count) {
	vector<int> unique_numbers;

	while (unique_numbers.size() != unique_numbers_count) {
		int number;
		cin >> number;

		//https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
		//first answer
		if (find(unique_numbers.begin(), unique_numbers.end(),
			number) == unique_numbers.end()) {

unique_numbers.push_back(number);
		}
	}

	return unique_numbers;
}

/// <summary>
/// 
/// </summary>
/// <param name="unique_numbers"></param>
/// <returns></returns>
vector<int> get_negative_numbers(vector<int>& unique_numbers) {
	vector<int> negative_numbers;

	for (int i = 0; i < unique_numbers.size(); i++) {
		int number = unique_numbers.at(i);

		if (number < 0) {
			negative_numbers.push_back(number);
		}
	}

	return negative_numbers;
}

vector<int> get_non_negative_numbers(vector<int>& unique_numbers) {
	const int UNIQUE_NUMBERS_COUNT = unique_numbers.size();
	vector<int> non_negative_numbers;

	for (int i = 0; i < UNIQUE_NUMBERS_COUNT; i++) {
		int number = unique_numbers.at(i);

		if (number >= 0) {
			non_negative_numbers.push_back(number);
		}
	}

	return non_negative_numbers;
}

bool non_negative_numbers_only_zeros(
	vector<int>& non_negative_numbers) {

	const int NON_NEGATIVE_NUMBERS_COUNT =
		non_negative_numbers.size();

	for (int i = 0; i < NON_NEGATIVE_NUMBERS_COUNT; i++) {
		int number = non_negative_numbers.at(i);

		if (number != 0) {
			return false;
		}
	}

	return true;
}

int find_sum_zero_opposite_elements(
	vector<int>& negative_numbers,
	vector<int>& non_negative_numbers) {

	const int NEGATIVE_NUMBERS_COUNT = 
		negative_numbers.size();

	const int ZERO_ELEMENT = 0;

	int three_numbers_sum_zero_count = 0;

	for (int i = 0; i < NEGATIVE_NUMBERS_COUNT; i++) {
		int opposite_number = -negative_numbers.at(i);

		if (find(non_negative_numbers.begin(),
			non_negative_numbers.end(),
			opposite_number) != non_negative_numbers.end()) {

			if (find(non_negative_numbers.begin(),
				non_negative_numbers.end(),
				ZERO_ELEMENT) != non_negative_numbers.end()) {

				cout << opposite_number << " "
					<< ZERO_ELEMENT << " "
					<< -opposite_number << endl;

				three_numbers_sum_zero_count++;
			}
		}
	}

	return three_numbers_sum_zero_count;
}

/// <summary>
/// finds three different from zero numbers whose sum is zero
/// </summary>
/// <param name="negative_numbers">vector with negative numbers</param>
/// <param name="non_negative_numbers">vector with non negative numbers</param>
/// <param name="positive_first">for skipping duplicate three numbers</param>
/// <returns>these three numbers whose sum is zero count</returns>
int find_sum_zero_sum_of_two_opposite(
	vector<int>& negative_numbers,
	vector<int>& non_negative_numbers,
	bool positive_first) {

	const int UNIQUE_NEGATIVE_NUMBERS_COUNT =
		negative_numbers.size();

	const int UNIQUE_NON_NEGATIVE_NUMBERS_COUNT =
		non_negative_numbers.size();

	int three_numbers_sum_zero_count = 0;

	for (int i = 0; i < UNIQUE_NEGATIVE_NUMBERS_COUNT; i++) {
		int first_number = negative_numbers.at(i);

		for (int j = i + 1; j < UNIQUE_NEGATIVE_NUMBERS_COUNT; j++) {
			int second_number = negative_numbers.at(j);

			int opposite_third_number =
				-(first_number + second_number);

			if (find(non_negative_numbers.begin(),
				non_negative_numbers.end(),
				opposite_third_number) != non_negative_numbers.end()) {

				if (positive_first) {
					if (first_number != 0 && second_number != 0
						&& opposite_third_number != 0) {

						three_numbers_sum_zero_count++;
					}
				}
				else {
					three_numbers_sum_zero_count++;
				}
			}
		}
	}

	return three_numbers_sum_zero_count;
}

void find_three_numbers_sum_zero(
	vector<int>& unique_negative_numbers,
	vector<int>& unique_non_negative_numbers) {

	if (non_negative_numbers_only_zeros(
		unique_non_negative_numbers)) {

		cout << "0" << endl;

		return;
	}
	else {
		const int UNIQUE_NEGATIVE_NUMBERS_COUNT =
			unique_negative_numbers.size();

		const int UNIQUE_NON_NEGATIVE_NUMBERS_COUNT =
			unique_non_negative_numbers.size();

		const int ZERO_ELEMENT = 0;

		int three_numbers_sum_zero_count = 
			find_sum_zero_opposite_elements(
				unique_negative_numbers,
				unique_non_negative_numbers);

		three_numbers_sum_zero_count +=
			find_sum_zero_sum_of_two_opposite(
				unique_negative_numbers,
				unique_non_negative_numbers,
				false);

		three_numbers_sum_zero_count +=
			find_sum_zero_sum_of_two_opposite(
				unique_negative_numbers,
				unique_non_negative_numbers,
				true);

		cout << endl << three_numbers_sum_zero_count << endl;
	}
}