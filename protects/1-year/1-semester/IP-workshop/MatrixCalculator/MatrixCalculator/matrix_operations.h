#ifndef __MATRIX_OPERATIONS__
#define __MATRIX_OPERATIONS__

struct MatrixDimensions {
	private:
		int rows_;
		int columns_;

	public:
		void set_rows(int rows) {
			rows_ = rows;
		}

		int get_rows() const {
			return rows_;
		}

		void set_columns(int columns) {
			columns_ = columns;
		}

		int get_columns() const {
			return columns_;
		}

		MatrixDimensions& operator=(const MatrixDimensions& dimens) {
			MatrixDimensions sizes;
			
			sizes.set_rows(dimens.get_rows());
			sizes.set_columns(dimens.get_columns());

			return sizes;
		}
};

struct MatrixRepresentation {
	private: 
		MatrixDimensions dimensions_;
		double** values_;

	public:
		MatrixRepresentation() { }
		
		MatrixRepresentation(MatrixDimensions& dimensions) : 
			dimensions_(dimensions), values_(NULL) { }

		void set_dimensions(MatrixDimensions& dimensions) {
			dimensions_ = dimensions;
		}

		MatrixDimensions get_dimensions() const {
			return dimensions_;
		}

		void set_values(double ** values) {


			const int ROWS = dimensions_.get_rows();
			const int COLUMNS = dimensions_.get_columns();

			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					values_[i][j] = values[i][j];
				}
			}
		}

		double** get_values() const {
			return values_;
		}

		void init_empty_matrix_values() {
			const int ROWS = dimensions_.get_rows();
			const int COLUMNS = dimensions_.get_columns();

			values_ = new double* [ROWS];

			for (int i = 0; i < ROWS; i++) {
				values_[i] = new double[COLUMNS];
			}
		}

		void destroy_matrix_values() {
			const int ROWS = dimensions_.get_rows();

			for (int i = 0; i < ROWS; i++) {
				delete[] values_[i];
			}

			delete[] values_;
			values_ = NULL;
		}
};

//Required
MatrixRepresentation matrix_multiplication_with_number(
	const char * filename);

MatrixRepresentation matrices_multiplication(
	MatrixRepresentation first_matrix,
	MatrixRepresentation second_matrix);

double calculate_matrix_determinant(
	MatrixRepresentation matrix);

MatrixRepresentation matrix_division_with_number(
	MatrixRepresentation matrix, double scalar);

MatrixRepresentation find_matrix_inverse(
	MatrixRepresentation matrix);

MatrixRepresentation matrix_transposition(
	MatrixRepresentation matrix);
//
////Optional
//void matrix_sum_substract(bool sum);
//void matrices_division();
//void singular_value_decomposition();

void matrix_operations_manager(int option);

#endif // !__MATRIX_OPERATIONS__