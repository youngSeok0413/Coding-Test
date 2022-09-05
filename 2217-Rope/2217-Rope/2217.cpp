#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	std::cin.ignore();

	std::vector<int> ropeType;
	int input = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		std::cin.ignore();
		ropeType.push_back(input);
	}

	std::sort(ropeType.begin(), ropeType.end());
	std::reverse(ropeType.begin(), ropeType.end());

	int maxWeight = 0;
	for (int i = 0; i < N; i++) {
		if ((i + 1) * ropeType[i] >= maxWeight) {
			maxWeight = (i + 1) * ropeType[i];
		}
	}

	std::cout << maxWeight;

	return 0;
}