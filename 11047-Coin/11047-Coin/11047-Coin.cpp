#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int N, K;
std::vector<int> arr;

int getCoinNum(int unit, int value) {
	int coin = 0;

	if (unit <= 0) {
		if (unit < 0)
			return -1;
		else {
			coin += value;
			return coin;
		}
	}
	else if (value%arr[unit] == 0) {
		coin += value / arr[unit];
		return coin;
	}
	else {
		coin += value / arr[unit];
		int newValue = value%arr[unit];
		int newUnit = unit-1;
		coin += getCoinNum(newUnit, newValue);
	}

	return coin;
}

int main() {

	std::string str;
	getline(std::cin, str);
	std::cin.clear();

	std::stringstream ss(str);
	ss >> N >> K;

	for (int i = 0; i < N; i++) {
		int input;
		std::cin >> input;
		arr.push_back(input);
		std::cin.clear();
	}

	std::cout << getCoinNum(N-1, K) << std::endl;

	return 0;
}
