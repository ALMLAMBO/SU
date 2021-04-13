#include <iostream>
#include "Logger.hpp"

using namespace std;

int main() {
	int a = 2;

	Logger<int> logger;
	logger.write("aa");
	logger.write("\n");
	logger.writeLine(&a);

	return 0;
}