#include <iostream>
#include <cmath>

void hanoi(int N, int start, int end, int buffer) {
	if (N==1) {
		std::cout << start << " " << end <<"\n";
	}
	else {
		hanoi(N - 1, start, buffer, end);
		std::cout << start << " " << end << "\n";
		hanoi(N - 1, buffer, end, start);
	}
}

int main() {
	int N;
	std::cin >> N;

	std::cout << pow(2, N) - 1 << "\n";
	hanoi(N, 1, 3, 2);

	return 0;
}