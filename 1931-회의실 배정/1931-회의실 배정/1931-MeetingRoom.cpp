#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

int N;
std::vector<std::pair<int, int>> arr;

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int countN(std::vector<std::pair<int, int>>& vec) {
	std::vector<std::pair<int, int>> schedule;

	if (vec.empty())
		return -1;

	std::sort(arr.begin(), arr.end(), compare);
	
	int toCompare = -1;
	for (int i = 0; i < N; i++) {
		if (arr[i].first >= toCompare) {
			toCompare = arr[i].second;
			schedule.push_back(arr[i]);
		}
	}

	return schedule.size();
}

int main() {
	std::cin >> N;
	std::cin.ignore();

	std::stringstream ss;
	std::pair<int, int> input;
	std::string str;

	for (int i = 0; i < N; i++) {
		str.clear();
		std::getline(std::cin, str);
		ss << str;
		ss >> input.first >> input.second;
		ss.clear();
		arr.push_back(input);
	}

	std::cout << countN(arr) << std::endl;

	return 0;
}