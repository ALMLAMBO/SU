#include <iostream>

using namespace std;

int main() {
	int rows, columns, number;

	cin >> rows >> columns >> number;
	int** matrix = new int* [rows];
	
	cout << endl;
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];

		for (int j = 0; j < columns; j++) {
			if (i == j) {
				matrix[i][j] = number;
			}
			else {
				matrix[i][j] = 0;
			}

			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = NULL;
	
	return 0;
}