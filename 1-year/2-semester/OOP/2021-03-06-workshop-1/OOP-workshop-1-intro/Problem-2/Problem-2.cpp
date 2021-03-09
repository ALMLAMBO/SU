#include <iostream>

using namespace std;

class Snake {
private:
	int x, y;

public:
	void set_x(int new_x) {
		this->x = new_x;
	}

	void set_y(int new_y) {
		this->y = new_y;
	}

	int get_x() const {
		return this->x;
	}

	int get_y() const {
		return this->y;
	}
};

int main() {
	return 0;
}