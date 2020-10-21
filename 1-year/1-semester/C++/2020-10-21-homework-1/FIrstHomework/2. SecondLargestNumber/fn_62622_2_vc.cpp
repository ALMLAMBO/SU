/**
*
* Solution to homework assignment 1
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

int main() {
	int input_number, largest_number = INT_MIN, 
		second_largest_number = INT_MIN;

	while (true) {
		cin >> input_number;

		if (input_number > largest_number) {
			largest_number = input_number;
		}
		else if (input_number > second_largest_number && 
			input_number < largest_number) {

			second_largest_number = largest_number;
		}
		else if (input_number <= 0) {
			break;
		}
	}

	cout << endl << second_largest_number << endl;

	return 0;
}