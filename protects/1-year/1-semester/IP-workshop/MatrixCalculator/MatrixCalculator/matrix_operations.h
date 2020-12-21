#ifndef __MATRIX_OPERATIONS__
#define __MATRIX_OPERATIONS__

struct maxtrix_dimesions {
	int rows;
	int columns;
};

struct matrix_representation {
	double** values;
	int rows;
	int columns;
};

struct matrix_elements_length {
	int* elements_length;
	int elements_length_count;
};

//Required
void matrix_multiplication_with_number();
void matrices_multiplication();
int calculate_matrix_determinant();
void matrix_division_with_number();
struct matrix_representation find_matrix_inverse();
struct matrix_representation matrix_transposition();
void singular_value_decomposition();

//Optional
void matrix_sum_substract(bool sum);
void matrices_division();

#endif // !__MATRIX_OPERATIONS__