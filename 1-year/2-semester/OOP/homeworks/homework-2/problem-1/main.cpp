#include <iostream>
#include "Result.hpp"

using namespace std;

Result<int> divide(const int first, const int second) {
	if (second == 0) {
		return Result<int>("Division by zero !");
	}
	return Result<int>(first / second);
}

int main() {
    Result<int> first = divide(5, 2);

    std::cout << "5 / 2 = ";
    if (first == Error()) {
        Error error = first.get_error().get_value();
        std::cout << error.get_message() << std::endl;
    }
    else {
        int value = first.get_result().get_value();

        std::cout << value << std::endl;
    }

    Result<int> second = divide(8, 0);
    std::cout << "8 / 0 = ";
    if (second == Error()) {
        Error error = second.get_error().get_value();
        std::cout << error.get_message() << std::endl;
    }
    else {
        std::cout << second.get_result().get_value() << std::endl;
    }

	return 0;
}