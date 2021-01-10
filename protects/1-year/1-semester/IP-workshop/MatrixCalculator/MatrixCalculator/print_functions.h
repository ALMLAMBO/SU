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

void print_matrix_det(MatrixRepresentation matrix,
	double determinant);

void print_matrix_invers(
	MatrixRepresentation input_matrix,
	MatrixRepresentation inverse_matrix);

#endif // !__PRINT_FUNCTIONS__