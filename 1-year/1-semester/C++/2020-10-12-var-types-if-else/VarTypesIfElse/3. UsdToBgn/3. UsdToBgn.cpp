#include <iostream>
#include <iomanip>

using namespace std;

const double USD_VALUE = 1.79549;

int main() {
	double input_usd;

	cin >> input_usd;

	double total_bgn = input_usd * USD_VALUE;

	cout << fixed << setprecision(2) << total_bgn << endl;

	return 0;
}