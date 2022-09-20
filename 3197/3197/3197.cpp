#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <vector>

struct Plane {
	char type;
	bool visited;
};

int R, C;
Plane plane[1501][1501] = { {{'X', false}, }, };
std::pair<int, int> goose[2];
std::pair<int, int> movement[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, }; // 0 = right, 1 = left, 2 = down, 3 = up
std::vector<std::pair<int, int>> ice;

//whether geese meet each other
bool whetherGeeseMeet() {
	std::queue<std::pair<int, int>> passed;
	plane[goose[0].first][goose[0].second].visited = true;
	passed.push(goose[0]);

	std::pair<int, int> next;
	while (!passed.empty()) {
		std::pair<int, int> now = passed.front();
		passed.pop();
		for (int i = 0; i < 4; i++) {
			next = { now.first + movement[i].first, now.second + movement[i].second };
			if (plane[next.first][next.second].type == 'L') {
				if (!plane[next.first][next.second].visited) {
					return true;
				}
			}
			else if (plane[next.first][next.second].type == '.') {
				if (!plane[next.first][next.second].visited) {
					plane[next.first][next.second].visited = true;
					passed.push(next);
				}
			}
		}
 	}

	for (int i = 1; i < R+1; i++) {
		for (int j = 1; j < C+1; j++) {
			plane[i][j].visited = false;
		}
	}

	return false;
}

//ice melting
void dayPassed() {

	if (ice.empty())
		return;

	std::queue<std::pair<int, int>> willBeMelted;
	std::pair<int, int> around;

	for (int i = 0; i < ice.size();) {
		bool plus = true;
		for (int k = 0; k < 4; k++) {
			around = { ice[i].first + movement[k].first, ice[i].second + movement[k].second };
			if (plane[around.first][around.second].type == '.') {
				willBeMelted.push(ice[i]);
				ice.erase(ice.begin() + i);
				plus = false;
				break;
			}
		}
		if (plus) {
			i++;
		}
	}

	while (!willBeMelted.empty()) {
		std::pair<int, int> toBeMelted = willBeMelted.front();
		plane[toBeMelted.first][toBeMelted.second].type = '.';
		willBeMelted.pop();
	}
}


int main() {
	std::cin >> R >> C;
	std::cin.ignore();

	std::string str;
	std::stringstream ss;
	char input;
	int numOfgoose = 0;
	for (int i = 1; i < R+1; i++) {
		std::getline(std::cin, str);
		ss << str;
		for (int j = 1; j < C+1; j++) {
			ss >> input;
			if (input == 'L') {
				goose[numOfgoose] = { i, j };
				numOfgoose++;
			}
			else if (input == 'X') {
				ice.push_back({i, j});
			}
			plane[i][j].type = input;
			plane[i][j].visited = false;
		}
		ss.clear();
		str.clear();
	}

	//code here
	int day = 0;
	while (!whetherGeeseMeet()) {
		dayPassed();
		day++;
	}

	std::cout << day;

	return 0;
}