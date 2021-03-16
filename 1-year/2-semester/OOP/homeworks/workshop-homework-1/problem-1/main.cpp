#include <iostream>
#include "Date.hpp"

using namespace std;

int main() {
#pragma region test adding days
#pragma endregion

#pragma region test removing days
#pragma endregion

#pragma region test leap year
	Date d1;
	cout << boolalpha << d1.is_leap_year() << endl;

	Date d2(14, 3, 2100);
	cout << boolalpha << d2.is_leap_year() << endl;

	Date d3(22, 5, 2012);
	cout << boolalpha << d3.is_leap_year() << endl;

	Date d4(31, 5, 2014);
	cout << boolalpha << d4.is_leap_year() << endl;
#pragma region

#pragma region test days to xmas
#pragma endregion

#pragma region test days to end of year
#pragma endregion

#pragma region test days to
#pragma endregion

#pragma region test is later than
#pragma endregion

	return 0;
}