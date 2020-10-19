#include <iostream>
#include <iomanip>

using namespace std;

const int BITCOIN_TO_BGN = 1168;
const double UAN_TO_USD = 0.15;
const double USD_TO_BGN = 1.76;
const double EUR_TO_BGN = 1.95;

int main() {
	int bitcoin_number;
	double chinese_uan;
	double commision;

	cin >> bitcoin_number >> chinese_uan >> commision;

	int converted_bitcoin = bitcoin_number * BITCOIN_TO_BGN;
	double converted_uan_to_bgn = chinese_uan * (UAN_TO_USD * USD_TO_BGN);
	double total_bgn = converted_bitcoin + converted_uan_to_bgn;

	double converted_eur = total_bgn / EUR_TO_BGN;
	double total_eur = (1 - (commision / 100)) * converted_eur;

	cout << fixed << setprecision(2) << total_eur << endl;

	return 0;
}