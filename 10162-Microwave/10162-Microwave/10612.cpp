#include <iostream>

int main() {
	int input;
	std::cin >> input;
	std::cin.ignore();

	int A = 0;
	int B = 0;
	int C = 0;

	if (input % 10 != 0) {
		std::cout << -1;
	}
	else {
		int A = input / 300;
		input = input % 300;
		int B = input / 60;
		input = input % 60;
		int C = input / 10;

		std::cout << A << " " << B << " " << C;
	}

	return 0;
}