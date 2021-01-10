#include <iostream>

using namespace std;

struct ArrayElement {
	private:
		int element_value_;
		bool visited_;

	public:
		ArrayElement() :
			element_value_(INT_MIN), visited_(false) {}

		ArrayElement(int element_value, bool visited) : 
			element_value_(element_value), 
			visited_(visited) {}

		int get_element_value() const {
			return element_value_;
		}

		bool is_visited() const {
			return visited_;
		}
};

struct Array {
	private:
		int array_elements_count_;
		ArrayElement* elements_;

	public:
		Array(int array_elements_count) : 
			array_elements_count_(array_elements_count),
			elements_(new ArrayElement[array_elements_count_]) {}

		void set_elements(ArrayElement* elements) {
			for (int i = 0; i < array_elements_count_; i++) {
				elements_[i] = elements[i];
			}
		}

		int get_array_elements_count() const {
			return array_elements_count_;
		}

		ArrayElement* get_elements() const {
			return elements_;
		}

		void destroy_elements() {
			delete[] elements_;
			elements_ = NULL;
		}
};

Array init(int elements_count);
bool ascending_order(Array array, int max_moves);

int main() {
	int max_moves = 0, elements_count = 0;
	cin >> max_moves;
	cin >> elements_count;

	Array array = init(elements_count);
	bool ascending = ascending_order(array, max_moves);

	cout << noboolalpha << ascending << endl;

	return 0;
}

Array init(int elements_count) {
	Array array(elements_count);

	int number;
	ArrayElement* elements = new ArrayElement[elements_count];

	for (int i = 0; i < elements_count; i++) {
		cin >> number;
		ArrayElement element(number, false);

		elements[i] = element;
	}

	delete[] elements;
	elements = NULL;

	return array;
}

bool check_ascending_order(Array array) {
	const int ELEMENTS_COUNT = array.get_array_elements_count();

	for (int i = 0; i < ELEMENTS_COUNT - 1; i++) {
		int current_element = array.get_elements()[i].get_element_value();
		int next_element = array.get_elements()[i + 1].get_element_value();

		if (current_element > next_element) {
			return false;
		}
	}

	return true;
}

bool ascending_order(Array array, int max_moves) {
	bool ascending = false;



	return ascending;
}