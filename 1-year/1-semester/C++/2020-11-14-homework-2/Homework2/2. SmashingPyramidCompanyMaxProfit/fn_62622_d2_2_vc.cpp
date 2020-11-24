/**
*
* Solution to homework assignment 2
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
#include <vector>
#include <algorithm>

using namespace std;

vector<double> get_increasing_values(
	vector<double>& share_values,
	int& index_to_start);

vector<double> get_share_values(int share_value_period_days);
double get_max_profit(vector<double>& share_values);

int main() {
	const int minimum_share_value_period_days = 3;
	const int maximum_share_value_period_days = 365;

	int share_value_period_days;

	cin >> share_value_period_days;

	if (share_value_period_days < minimum_share_value_period_days
		|| share_value_period_days > maximum_share_value_period_days) {

		cout << "Invalid period of days" << endl;

		while (share_value_period_days < minimum_share_value_period_days
			|| share_value_period_days > maximum_share_value_period_days) {

			cout << "Enter valid period of days" << endl;
			cin >> share_value_period_days;
		}
	}

	vector<double> share_values = get_share_values(
		share_value_period_days);

	double max_profit = get_max_profit(share_values);

	cout << max_profit << endl;

	return 0;
}

/// <summary>
/// gets all share values in increasing order
/// </summary>
/// <param name="share_values">reference to all share values</param>
/// <param name="index_to_start">reference to starting index</param>
/// <returns>double vector with all increasing share values</returns>
vector<double> get_increasing_values(
	vector<double>& share_values,
	int& index_to_start) {

	vector<double> increasing_share_values;

	double share_value_current_day =
		share_values.at(index_to_start);

	double share_value_next_day =
		share_values.at(index_to_start + 1);

	while (share_value_current_day < share_value_next_day) {
		if (index_to_start + 1 < share_values.size()) {
			share_value_current_day =
				share_values.at(index_to_start);

			share_value_next_day =
				share_values.at(index_to_start + 1);

			if (find(increasing_share_values.begin(),
				increasing_share_values.end(),
				share_value_current_day) == increasing_share_values.end()) {

				increasing_share_values
					.push_back(share_value_current_day);
			}

			if (find(increasing_share_values.begin(),
				increasing_share_values.end(),
				share_value_next_day) == increasing_share_values.end()) {

				increasing_share_values
					.push_back(share_value_next_day);
			}
		}
		else {
			break;
		}

		index_to_start++;
	}

	return increasing_share_values;
}

/// <summary>
/// gets valid share values entered from user
/// </summary>
/// <param name="share_value_period_days">share values for n days</param>
/// <returns>double vector with all share values</returns>
vector<double> get_share_values(int share_value_period_days) {
	const double minimum_share_value = 0.1f;
	const double maximum_share_value = 100.0f;

	vector<double> share_values;
	double share_value;

	for (int i = 0; i < share_value_period_days; i++) {
		cin >> share_value;

		if (share_value < minimum_share_value
			|| share_value > maximum_share_value) {

			cout << "Invalid share value" << endl;

			while (share_value < minimum_share_value
				|| share_value > maximum_share_value) {

				cin >> share_value;
			}
		}

		share_values.push_back(share_value);
	}

	return share_values;
}

/// <summary>
/// calculates max profit from all share values
/// </summary>
/// <param name="share_values"></param>
/// <returns>max profit value</returns>
double get_max_profit(vector<double>& share_values) {
	const int share_values_period_days = share_values.size();
	double max_profit = 0;
	
	for (int i = 0; i < share_values_period_days - 1; i++) {
		vector<double> increasing_share_values =
			get_increasing_values(share_values, i);

		if (increasing_share_values.size() != 0) {
			//https://www.geeksforgeeks.org/how-to-find-the-minimum-and-maximum-element-of-a-vector-using-stl-in-c/
			double min_share_value_increasing_values = *min_element(
				increasing_share_values.begin(),
				increasing_share_values.end());

			double max_share_value_increasing_values = *max_element(
				increasing_share_values.begin(),
				increasing_share_values.end());

			max_profit += max_share_value_increasing_values -
				min_share_value_increasing_values;
		}
	}

	return max_profit;
}