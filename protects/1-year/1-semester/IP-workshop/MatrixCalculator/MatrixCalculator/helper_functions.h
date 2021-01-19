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
* <header file with helper functions>
*
*/

#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__
#include <fstream>
#include "matrix_operations.h"

struct LongestElementsLengths {
private:
	int elements_count_;
	int* elements_lengths_;

public:
	LongestElementsLengths() :
		elements_count_(INT_MIN),
		elements_lengths_(NULL) {}

	void set_elements_count(int elements_count) {
		elements_count_ = elements_count;
	}

	void set_elements_lengths(int* elements_lengths) {
		for (int i = 0; i < elements_count_; i++) {
			elements_lengths_[i] = elements_lengths[i];
		}
	}

	int get_elements_count() const {
		return elements_count_;
	}

	int* get_elements_lengths() const {
		return elements_lengths_;
	}

	void init_elements_lengths() {
		elements_lengths_ = new int[elements_count_];
	}

	void destroy_elements_elements_lengths() {
		delete[] elements_lengths_;
		elements_lengths_ = NULL;
	}
};

double calclulate_sqrt(double number);
double pow_number(double number, int exponent);
double absolute_value(double number);

MatrixDimensions get_matrix_dimensions(std::ifstream& file);
double** get_matrix_values(std::ifstream& file,
	MatrixDimensions dimensions);

MatrixRepresentation get_matrix(const char* filename);
double get_scalar(const char* filename);

int get_element_length(double number);

LongestElementsLengths get_columns_longest_elements(
	MatrixRepresentation matrix, int columns);

#endif // !__HELPER_FUNCTIONS__