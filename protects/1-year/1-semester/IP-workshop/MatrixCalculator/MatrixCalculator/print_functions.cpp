#include <iostream>
#include "print_functions.h"
#include "matrix_operations.h"

using namespace std;

/// <summary>
/// Prints available operations with matrices
/// </summary>
void print_available_operations() {
	cout << "1. Matrix multiplication with number" << endl;
	cout << "2. Matrices multiplication" << endl;
	cout << "3. Find matrix determinant" << endl;
	cout << "4. Matrix division with number" << endl;
	cout << "5. Find inverse matrix" << endl;
	cout << "6. Matrix transpose" << endl;
	cout << "7. Singular value decomposition (SVD)" << endl;
	cout << "(Optional)8. Matrices sum" << endl;
	cout << "(Optional)9. Matrices subtraction" << endl;
	cout << "(Optional)10. Matrices division" << endl;
}