/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main() {
	const int minimum_required_number = 2;
	const int maximum_required_number = pow(10, 9);

	int input_number;

	cin >> input_number;

	if (input_number >= minimum_required_number &&
		input_number <= maximum_required_number) {


	}
	else {
		cout << endl << "Invalid input data" << endl;
	}

	return 0;
}