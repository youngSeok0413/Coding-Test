#include <iostream>
#include <string>
#include <sstream>
#include <queue>
int R, C;
std::pair<int, int> goose[2];
std::pair<int, int> movement[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, }; // 0 = right, 1 = left, 2 = down, 3 = up

bool whetherGeeseMeet(char** plane) {
	std::queue<std::pair<int, int>> passed;

	std::pair<int, int> nowLoc = goose[0];
	std::pair<int, int> nextLoc[4];
	for (int i = 0; i < 4; i++) {
		nextLoc[i] = {nowLoc.first + movement[i].first, nowLoc.second + movement[i].second };
		if (nextLoc[i].first > 0 && nextLoc[i].first < R 
			&& nextLoc[i].second > 0 && nextLoc[i].second < R) {
			if (plane[nextLoc[i].first][nextLoc[i].second] == 'L') {
				return true; // the end
			}
			else if (plane[nextLoc[i].first][nextLoc[i].second] == '.') {
				passed.push(nextLoc[i]);
			}
		}
	}
}

int main() {
	std::cin >> R >> C;
	std::cin.ignore();

	char** plane = new char*[R];
	for (int i = 0; i < R; i++) {
		plane[i] = new char[C];
	}

	std::string str;
	std::stringstream ss;
	char input;
	int numOfgoose = 0;
	for (int i = 0; i < R; i++) {
		std::getline(std::cin, str);
		ss << str;
		for (int j = 0; j < C; j++) {
			ss >> input;
			if (input == 'L') {
				goose[numOfgoose] = {i, j};
				numOfgoose++;
			}
			plane[i][j] = input;
		}
		ss.clear();
		str.clear();
	}

	//code here


	for (int i = 0; i < R; i++) {
		delete[] plane[i];
	}
	delete[] plane;

	return 0;
}