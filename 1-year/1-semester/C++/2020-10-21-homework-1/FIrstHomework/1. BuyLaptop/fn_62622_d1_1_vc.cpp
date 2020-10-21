/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Aleksander Marinov
* @idnumber 62622
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main() {
	int years_old, laptop_price, toy_price;

	cin >> years_old >> laptop_price >> toy_price;

	const int money_to_spend_drawing_friends = 5, 
		give_money_every_even_birthday = 30;

	int total_gathered_from_birthdays_money = 0;

	for (int i = 1; i <= years_old; i++) {
		if (i % 2 == 0) {
			total_gathered_from_birthdays_money += ((i / 2) * 30) - 5;
		}
		else {
			total_gathered_from_birthdays_money += toy_price;
		}
	}

	int difference_between_laptop_price_and_gathered_money =
		abs(total_gathered_from_birthdays_money - laptop_price);

	if (total_gathered_from_birthdays_money > laptop_price) {
		cout << endl << "yes" << endl 
			<< difference_between_laptop_price_and_gathered_money << endl;
	}
	else {
		cout << endl << "no" << endl
			<< difference_between_laptop_price_and_gathered_money << endl;
	}

	return 0;
}