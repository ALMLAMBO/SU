#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__

double calclulate_sqrt(double number);
double pow_number(double number, int exponent);
double absolute_value(double number);
double** get_matrix_values(std::ifstream& file,
	struct matrix_dimensions * sizes);

int find_number_length(double number);

struct matrix_dimensions * get_matrix_dimensions(
	std::ifstream& file);

struct matrix_elements_length * get_matrix_elements_length(
	struct matrix_representation * matrix);

int get_longest_number_length(
	struct matrix_elements_length * elements);

#endif // !__HELPER_FUNCTIONS__