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
* <header file with print functions>
*
*/

#ifndef __PRINT_FUNCTIONS__
#define __PRINT_FUNCTIONS__

#include "matrix_operations.h"

void print_available_operations();
void print_matrices_operations(
	MatrixRepresentation first_input_matrix,
	MatrixRepresentation second_input_matrix,
	MatrixRepresentation result_matrix,
	char operation_symbol);

void print_matrix_mult_divide_number(
	MatrixRepresentation input_matrix,
	MatrixRepresentation result_matrix,
	char operation_symbol,
	bool multiply,
	double scalar);

void print_matrix_inverse_transpose(
	MatrixRepresentation input_matrix,
	MatrixRepresentation result_matrix,
	const char* message,
	bool transpose);

void print_matrix_det(MatrixRepresentation matrix,
	double determinant, bool determinant_exists);

void print_matrix(char matrix_letter,
	MatrixRepresentation matrix);

#endif // !__PRINT_FUNCTIONS__