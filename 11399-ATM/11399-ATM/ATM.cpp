#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
	int N = 0;
	std::cin >> N;
	std::cin.ignore();

	std::vector<int> Arr(N);

	std::string str;
	std::getline(std::cin, str);

	std::stringstream stream(str);

	int input = 0;
	for (int i = 0; stream >> input; i++) {
		Arr[i] = input;
	}

	std::sort(Arr.begin(), Arr.end());
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (N-i)*Arr[i];
	}

	std::cout << sum << std::endl;

	return 0;
}