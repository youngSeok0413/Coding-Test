#include <iostream>

int main() {
	int N = 0;
	std::cin >> N;

	int largeBasket = 0;
	int smallBasket = 0;

	largeBasket = N/5;

	if (largeBasket > 0) {
		N -= 5 * largeBasket;

		while (true) {
			if (N % 3 == 0) {
				smallBasket = N / 3;
				break;
			}
			else {
				if (largeBasket > 0) {
					largeBasket--;
					N += 5;
				}
				else {
					smallBasket = -1;
					break;
				}
			}
		}
	}
	else {
		if (N % 3 == 0) {
			smallBasket = N / 3;
		}
		else {
			smallBasket = -1;
		}
	}

	std::cout << largeBasket + smallBasket << std::endl;

	return 0;
}