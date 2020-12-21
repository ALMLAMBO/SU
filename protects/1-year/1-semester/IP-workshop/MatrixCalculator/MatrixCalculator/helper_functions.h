#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__

#include <fstream>
using namespace std;

double calclulate_sqrt(double number);
double pow_number(double number, int exponent);
double absolute_value(double number);
int find_number_length(double number);

struct matrix_dimensions get_matrix_dimensions(
	ifstream& file);

struct matrix_elements_length get_matrix_elements_length(
	struct matrix_representation matrix);

int get_longest_number_length(
	struct matrix_elements_length elements);

#endif // !__HELPER_FUNCTIONS__