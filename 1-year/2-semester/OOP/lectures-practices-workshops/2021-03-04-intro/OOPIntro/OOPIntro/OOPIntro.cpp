#include <iostream>

using namespace std;

class Point {
public:
	Point() {
		this -> x = 0;
		this -> y = 0;
	}

	void set_x(double new_x) {
		this->x = new_x;
	}

	void set_y(double new_y) {
		y = new_y;
	}

	double get_x() {
		return x;
	}

	double get_y() {
		return y;
	}

	double distance_to(Point other) {
		return sqrt(pow(other.x - this -> x, 2) 
			+ pow(other.y - this -> y, 2));
	}

private:
	double x = 0;
	double y = 0;
};

int main() {
	Point first;

	first.set_x(5);
	first.set_y(4);

	Point second;
	second.set_x(6);
	second.set_y(5);

	cout << first.distance_to(second) << endl;

	return 0;
}