/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 3
* @compiler VC
*
*/
#include <iostream>
#include <numeric>

using namespace std;

struct Fraction {
	int numerator;
	int denominator;

	Fraction(int numer, int denom) : 
		numerator(numer), denominator(denom) {}
};

Fraction add_substract(
	Fraction first_fraction,
	Fraction second_fraction,
	int multiplier);

Fraction mult_divide(
	Fraction first_fraction,
	Fraction second_fraction,
	bool mult);

void operations_manager();

int main() {
	operations_manager();

	return 0;
}

bool valid_fraction(int number) {
	return number != 0;
}

//https://www.codegrepper.com/code-examples/cpp/c%2B%2B+gcd+function
//Second algorithm
int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

//http://www.trytoprogram.com/cpp-examples/cplusplus-program-to-find-lcm/
//First answer
int lcm(int a, int b) {
	int max_value = a > b ? a : b;

	while (true) {
		if (max_value % a == 0 && max_value % b == 0) {
			break;
		}

		max_value++;
	}

	return max_value;
}

void print_fraction(Fraction fraction) {
	cout << endl << fraction.numerator << " "
		<< fraction.denominator << endl;
}

void operations_manager() {
	int numer, denom;
	char operation;

	cin >> numer >> denom;
	cin >> operation;

	Fraction first_fraction(numer, denom);
	cin >> numer >> denom;
	Fraction second_fraction(numer, denom);

	switch (operation) {
		case '+': {
				Fraction result_fraction_add =
					add_substract(first_fraction, second_fraction, 1);
				
				print_fraction(result_fraction_add);
			}
			break;

		case '-': {
			Fraction result_fraction_sub =
				add_substract(first_fraction, second_fraction, -1);

			print_fraction(result_fraction_sub);
		}
			break;

		case '*': {
			Fraction result_fraction_mult =
				mult_divide(first_fraction, second_fraction, true);
			
			print_fraction(result_fraction_mult);
		}
			break;
		
		case '/': {
			Fraction result_fraction_div =
				mult_divide(first_fraction, second_fraction, false);
		
			print_fraction(result_fraction_div);
		}
			break;

		default: cout << "Invalid operation" << endl; break;
	}
}

Fraction add_substract(
	Fraction first_fraction,
	Fraction second_fraction,
	int multiplier) {

	Fraction result_fraction(INT_MIN, INT_MIN);
	bool valid_first_denom = valid_fraction(first_fraction.denominator);
	bool valid_second_denom = valid_fraction(second_fraction.denominator);

	if(valid_first_denom && valid_second_denom) {

		int gcd_first_fraction = gcd(
			first_fraction.numerator, 
			first_fraction.denominator);

		first_fraction.numerator /= gcd_first_fraction;
		first_fraction.denominator /= gcd_first_fraction;

		int gcd_second_fraction = gcd(
			second_fraction.numerator, 
			second_fraction.denominator);

		second_fraction.numerator /= gcd_second_fraction;
		second_fraction.denominator /= gcd_second_fraction;

		int lcm_denom = lcm(
			first_fraction.denominator,
			second_fraction.denominator);

		int first_numerator_after_finding_lcm = 
			lcm_denom / first_fraction.denominator;

		int second_numerator_after_finding_lcm =
			lcm_denom / second_fraction.denominator;

		int result_numerator = first_numerator_after_finding_lcm +
			multiplier * second_numerator_after_finding_lcm;

		int gcd_result_fract = gcd(result_numerator, lcm_denom);
		result_numerator /= gcd_result_fract;
		lcm_denom /= gcd_result_fract;

		result_fraction.numerator = result_numerator;
		result_fraction.denominator = lcm_denom;
	}

	return result_fraction;
}

Fraction mult_divide(
	Fraction first_fraction,
	Fraction second_fraction,
	bool mult) {

	Fraction result_fraction(INT_MIN, INT_MIN);
	bool valid_first_denom = valid_fraction(first_fraction.denominator);
	bool valid_second_denom = valid_fraction(second_fraction.denominator);

	if (valid_first_denom && valid_second_denom) {
		if (!mult) {
			bool valid_second_numerator = 
				valid_fraction(second_fraction.numerator);

			if (!valid_second_numerator) {
				return result_fraction;
			}

			int temp = second_fraction.denominator;
			second_fraction.denominator = second_fraction.numerator;
			second_fraction.numerator = temp;
		}

		int gcd_first_fraction = gcd(
			first_fraction.numerator,
			first_fraction.denominator);

		first_fraction.numerator /= gcd_first_fraction;
		first_fraction.denominator /= gcd_first_fraction;

		int gcd_second_fraction = gcd(
			second_fraction.numerator,
			second_fraction.denominator);

		second_fraction.numerator /= gcd_second_fraction;
		second_fraction.denominator /= gcd_second_fraction;

		int result_numerator = first_fraction.numerator *
			second_fraction.numerator;

		int result_denominator = first_fraction.denominator * 
			second_fraction.denominator;
		
		int gcd_result_fract = gcd(result_numerator, result_denominator);
		result_numerator /= gcd_result_fract;
		result_denominator /= gcd_result_fract;

		result_fraction.numerator = result_numerator;
		result_fraction.denominator = result_denominator;
	}
	
	return result_fraction;
}