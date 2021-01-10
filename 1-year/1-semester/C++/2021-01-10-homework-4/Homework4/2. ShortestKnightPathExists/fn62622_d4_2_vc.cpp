/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <set>
#include <queue>

using namespace std;

struct Point {
	private:
		int x_, y_, dist_;

	public:
		Point(int x, int y, int dist = 0) : 
			x_(x), y_(y), dist_(dist) {}

		void set_x(int x) {
			x_ = x;
		}

		void set_y(int y) {
			y_ = y;
		}

		void set_dist(int dist) {
			dist_ = dist;
		}

		int get_x() const {
			return x_;
		}

		int get_y() const {
			return y_;
		}

		int get_dist() const {
			return dist_;
		}

		bool operator<(const Point& other) const {
			return x_ < other.get_x() 
				|| (x_ == other.get_x() && y_ < other.get_y());
		}
};

bool can_reach_destination(
	Point start, Point end, 
	Point chess_dimensions,
	int max_moves);

Point valid_chess_dimensions(Point chess_dimensions) {
	Point valid_chess_dims(INT_MIN, INT_MIN);

	if (chess_dimensions.get_x() < 3 
		|| chess_dimensions.get_y() < 3) {

		cout << "Invalid chess sizes" << endl;
		return valid_chess_dims;
	}

	valid_chess_dims.set_x(chess_dimensions.get_x());
	valid_chess_dims.set_y(chess_dimensions.get_y());
	valid_chess_dims.set_dist(chess_dimensions.get_dist());

	return valid_chess_dims;
}

Point valid_coordinates(Point p) {
	Point valid(INT_MIN, INT_MIN);

	if (p.get_x() > 200 || p.get_y() > 200) {
		cout << "Invalid coordinates" << endl;
		return valid;
	}

	valid.set_x(p.get_x());
	valid.set_y(p.get_y());
	valid.set_dist(p.get_dist());

	return valid;
}

int main() {
	int width, height;
	cin >> width >> height;
	Point chess_dimensions(width, height);
	
	chess_dimensions = valid_chess_dimensions(chess_dimensions);
	
	if (chess_dimensions.get_x() == INT_MIN
		&& chess_dimensions.get_y() == INT_MIN) {

		return -1;
	}

	cin >> width >> height;
	Point start(width, height);
	start = valid_coordinates(start);
	if (start.get_x() == INT_MIN 
		&& start.get_y() == INT_MIN) {

		return -1;
	}

	cin >> width >> height;
	Point end(width, height);
	end = valid_coordinates(end);
	if (end.get_x() == INT_MIN
		&& end.get_y() == INT_MIN) {

		return -1;
	}

	int max_moves;
	cin >> max_moves;
	if (max_moves > 30) {
		return -1;
	}

	bool can_reach_coordinates =
		can_reach_destination(start, end,
			chess_dimensions, max_moves);

	cout << boolalpha << can_reach_coordinates << endl;
	
	return 0;
}

bool valid_coordinates(int x, int y, Point chess_dimensions) {
	if ((x >= 1 && x <= chess_dimensions.get_x())
		&& (y >= 1 && y <= chess_dimensions.get_y())) {

		return true;
	}

	return false;
}

int solve_knight_tour(Point start, Point end, Point chess_dimensions, 
	queue<Point> queue, set<Point> visited) {

	if (queue.empty()) {
		return INT_MAX;
	}

	Point current = queue.front();
	queue.pop();
	
	int current_x = current.get_x();
	int current_y = current.get_y();
	int dist = current.get_dist();

	if (current_x == end.get_x() 
		&& current_y == end.get_y()) {

		return dist;
	}

	if (!visited.count(current)) {
		visited.insert(current);
	}

	int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

	for (int i = 0; i < 8; i++) {
		int next_x = current_x + row[i];
		int next_y = current_y + col[i];

		if (valid_coordinates(next_x, next_y, chess_dimensions)) {
			Point p(next_x, next_y, dist + 1);
			queue.push(p);
		}
	}

	return solve_knight_tour(current, end, 
		chess_dimensions, queue, visited);
}

int find_min_knight_moves(Point start, Point end,
	Point chess_dimensions) {

	set<Point> visited;
	queue<Point> queue;
	queue.push(start);

	return solve_knight_tour(start, end, 
		chess_dimensions, queue, visited);
}

bool can_reach_destination(Point start, Point end,
	Point chess_dimensions, int max_moves) {

	int knight_moves = find_min_knight_moves(
		start, end, chess_dimensions);

	bool equal = false;
	if (knight_moves > max_moves) {
		equal = false;
	}
	else if ((knight_moves - max_moves) % 2 == 0) {
		equal = true;
	}

	return equal;
}