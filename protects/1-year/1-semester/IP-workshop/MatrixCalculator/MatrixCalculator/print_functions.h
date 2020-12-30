#ifndef __PRINT_FUNCTIONS__
#define __PRINT_FUNCTIONS__

void print_available_operations();
void print_matrix(struct matrix_representation * matrix);

void print_matrix_multiplication_division_with_number(
	struct matrix_representation* matrix,
	double scalar, bool multiplication);

void print_matrices_multiplication_division(
	struct matrix_representation first_matrix,
	struct matrix_representation second_matrix,
	bool division);

#endif // !__PRINT_FUNCTIONS__