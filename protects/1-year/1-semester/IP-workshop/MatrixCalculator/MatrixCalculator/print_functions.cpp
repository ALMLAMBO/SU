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

/// <summary>
/// Prints matrix
/// </summary>
/// <param name="matrix">input matrix</param>
void print_matrix(struct matrix_representation* matrix) {

}

/// <summary>
/// Prints result matrix after mult or division with number
/// </summary>
/// <param name="matrix">result matrix</param>
/// <param name="scalar">scalar value</param>
/// <param name="multiplication">true for mult, false for division</param>
void print_matrix_multiplication_division_with_number(
	struct matrix_representation* matrix,
	double scalar, bool multiplication) {


}

/// <summary>
/// Prints result matrix after matrices mult or division
/// </summary>
/// <param name="first_matrix">first matrix</param>
/// <param name="second_matrix">second matrix</param>
/// <param name="division">true for division, false for multiplication</param>
void print_matrices_multiplication_division(
	struct matrix_representation first_matrix,
	struct matrix_representation second_matrix,
	bool division) {


}