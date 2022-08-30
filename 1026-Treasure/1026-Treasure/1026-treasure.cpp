#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int N;
std::vector<int> A;
std::vector<int> B; //must fixed

void getInput() {
	std::cin >> N;
	std::cin.ignore();

	std::string str;
	std::stringstream ss;

	std::getline(std::cin, str);
	ss << str;
	str.clear();
	for (int i = 0; i < N; i++) {
		int input;
		ss >> input;
		A.push_back(input);
		std::cin.clear();
	}

	ss.clear();

	std::getline(std::cin, str);
	ss << str;
	str.clear();
	for (int i = 0; i < N; i++) {
		int input;
		ss >> input;
		B.push_back(input);
		std::cin.clear();
	}
}

int getSmallestSum() {
	if (A.empty() || B.empty()) {
		return -1;
	}
	else {
		int sum = 0;
		
		for (int i = 0; i < N; i++) {
			auto aMax = std::max_element(A.begin(), A.end());
			auto bMin = std::min_element(B.begin(), B.end());
			sum += (*aMax) * (*bMin);
			A.erase(aMax);
			B.erase(bMin);
		}

		return sum;
	}

	return -1;
}

int main() {
	getInput();
	std::cout << getSmallestSum() << std::endl;
	return 0;
}