#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int playground_size;
	double tile_width, tile_height;
	int bench_width, bench_height;

	cin >> playground_size;
	cin >> tile_width >> tile_height;
	cin >> bench_width >> bench_height;

	int playground_area = pow(playground_size, 2);
	int bench_area = bench_width * bench_height;
	int area_to_cover_with_tiles = playground_area - bench_area;

	double tile_area = tile_width * tile_height;
	double needed_tiles = area_to_cover_with_tiles / tile_area;
	double time_to_set_tiles = needed_tiles * 0.2;

	cout << needed_tiles << endl << time_to_set_tiles << endl;

	return 0;
}