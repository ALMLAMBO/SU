#include <iostream>

using namespace std;

int main() {
	int num1, num2;

	cin >> num1;
	cin >> num2;

	int temp_num;
	
	temp_num = num2;
	num2 = num1;
	num1 = temp_num;

	cout << "First number = " << num1 << endl
		<< "Second number = " << num2 << endl;
}