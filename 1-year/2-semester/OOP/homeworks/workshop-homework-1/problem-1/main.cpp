/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alexander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*/
#include <iostream>
#include "Date.hpp"

using namespace std;

int main() {
#pragma region test adding days
	//Date d(10, 2, 2021);
	//d.add_days(5);
	//d.print();

	//d.add_days(100);
	//d.remove_days(50);
	//d.print();

#pragma endregion

#pragma region test removing days
#pragma endregion

#pragma region test leap year
	/*Date d1;
	cout << boolalpha << d1.is_leap_year() << endl;

	Date d2(14, 3, 2100);
	cout << boolalpha << d2.is_leap_year() << endl;

	Date d3(22, 5, 2012);
	cout << boolalpha << d3.is_leap_year() << endl;

	Date d4(31, 5, 2014);
	cout << boolalpha << d4.is_leap_year() << endl;*/
#pragma region

#pragma region test days to xmas
	//Date d5(15, 3, 2015);
	//int result = d5.days_to_xmas();
	//cout << result << endl;
#pragma endregion

#pragma region test days to end of year
	//cout << d5.days_to_end_of_year() << endl;
#pragma endregion

#pragma region test days to
	Date a(1, 12, 2018);
	Date b(15, 3, 2020);

	int c = a.days_to(b);
	cout << c << endl;
#pragma endregion

#pragma region test is later than
	/*Date temp;
	cout << boolalpha << d.is_later_than(temp) << endl;*/
#pragma endregion

	return 0;
}