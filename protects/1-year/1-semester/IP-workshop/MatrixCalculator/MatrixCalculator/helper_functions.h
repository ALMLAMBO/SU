#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__
#include <fstream>
#include "matrix_operations.h"

double calclulate_sqrt(double number);
double pow_number(double number, int exponent);
double absolute_value(double number);

MatrixDimensions get_matrix_dimensions(std::ifstream& file);
double** get_matrix_values(std::ifstream& file, 
	MatrixDimensions dimensions);

MatrixRepresentation get_matrix(std::ifstream file);
double get_scalar(std::ifstream& file);

#endif // !__HELPER_FUNCTIONS__