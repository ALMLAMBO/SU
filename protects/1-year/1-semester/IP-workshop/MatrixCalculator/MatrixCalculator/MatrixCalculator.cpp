/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @compiler VC
*
* <main file>
*
*/


#include <iostream>
#include "print_functions.h"
#include "matrix_operations.h"

using namespace std;

int main() {
	int option;

	print_available_operations();
	cout << endl << "Enter option" << endl;
	cin >> option;
	
	matrix_operations_manager(option);
}