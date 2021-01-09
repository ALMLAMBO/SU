#ifndef __HELPER_FUNCTIONS__
#define __HELPER_FUNCTIONS__
#include <fstream>
#include "matrix_operations.h"

struct MatrixElementsLength {
	private:
		int* elements_lengths_;
		int elements_count_;

	public:
		MatrixElementsLength() :
			elements_lengths_(NULL), 
			elements_count_(INT_MIN) {}

		void set_elements_lengths(int* elements_lengths) {
			for (int i = 0; i < elements_count_; i++) {
				elements_lengths_[i] = elements_lengths[i];
			}
		}

		void set_elements_count(int elements_count) {
			elements_count_ = elements_count;
		}

		int* get_elements_lengths() const {
			return elements_lengths_;
		}

		int get_elements_count() const {
			return elements_count_;
		}

		void init_elements_lengths() {
			elements_lengths_ = new int[elements_count_];
		}

		void destroy_elements_lengths() {
			delete[] elements_lengths_;
			elements_lengths_ = NULL;
		}
};

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

MatrixRepresentation get_matrix(const char * filename);
double get_scalar(const char * filename);

int get_element_length(double number);
MatrixElementsLength get_matrix_elements_lengths(
	MatrixRepresentation matrix);

LongestElementsLengths get_columns_longest_elements(
	MatrixElementsLength matrix_elements_lengths,
	int columns);

#endif // !__HELPER_FUNCTIONS__