#include <iostream>
#include <queue>
#include <chrono>

unsigned long int howLong(std::pair<int, int> (*fptr)(int), int data) {
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	fptr(data);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::nanoseconds nano = end - start;
	return nano.count();
}


struct Node {
	int data;
	bool visited;
};

//movement : 0=right, 1=left, 2=down, 3=up(�ٵ��� ������� edge�� ��)
std::pair<int, int> movements[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

Node graph[10 + 2][10 + 2] = { {{0, false}, }, }; // ���� 100x100 �� �ִ� �Ͱ� �迭�� ������ ���鳢�� ����Ǿ� �ִ�.

//BFS(���� �켱 Ž��) : ������ �迭�� ��ġ�� ������, �ƴϸ� (-1, -1)
std::pair<int, int> BFS(int toFind) {
	std::queue<std::pair<int, int>> queue;

	queue.push({1, 1}); // ����
	graph[1][1].visited = true;

	while (!queue.empty()) {
		std::pair<int, int> nowLoc = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++) {
			std::pair<int, int> toGo = 
				{ nowLoc.first + movements[i].first, nowLoc.second + movements[i].second };

			if (graph[toGo.first][toGo.second].data == 0); // edge�� ���� �κ�(���ǻ� ����)

			else if (!graph[toGo.first][toGo.second].visited) {
				graph[toGo.first][toGo.second].visited = true; // �� �� ǥ��
				if (graph[toGo.first][toGo.second].data == toFind) {
					return toGo;
				}
				queue.push(toGo); 
			}
		}
	}

	return {-1, -1};
}

//DFS

std::pair<int, int> result = { -1, -1 };

void semi_DFS(std::pair<int, int> nowLoc, int toGo) {
	if (result.first != -1) {
		return;
	}
	else if (graph[nowLoc.first][nowLoc.second].data == toGo) {
		result = nowLoc;
		return;
	}
	else {
		std::pair<int, int> res = {-1, -1};
		for (int i = 0; i < 4; i++) {
			std::pair<int, int> next =
				{ nowLoc.first + movements[i].first, nowLoc.second + movements[i].second };

			if (graph[next.first][next.second].data == 0); // edge�� ���� �κ�(���ǻ� ����)
			else if (!graph[next.first][next.second].visited) {
				graph[next.first][next.second].visited = true; // �� �� ǥ��
				semi_DFS(next, toGo);
			}
		}
		return;
	}
}

std::pair<int, int> DFS(int toGo) {
	semi_DFS({1,1}, toGo);
	return result;
}

//ó�� ���·� �������
void reset() {
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			graph[i][j].visited = false;
		}
	}
}

void compare(int where) {
	reset();
	std::cout << "find " << where << std::endl;
	std::pair<int, int> bfs = BFS(where);
	reset();
	unsigned long int t1 = howLong(BFS, where);
	std::cout << "BFS ��ġ : " << bfs.first << " " << bfs.second << " �ð� : " << t1 << std::endl;
	reset();
	std::pair<int, int> dfs = DFS(where);
	reset();
	unsigned long int t2 = howLong(DFS, where);
	std::cout << "DFS ��ġ : " << dfs.first << " " << dfs.second << " �ð� : " << t2 << std::endl;
	reset();
}

int main() {
	int num = 1;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11;j++) {
				graph[i][j].data = num;
				num++;
		}
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			std::cout << graph[i][j].data << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			compare(graph[i][j].data);
		}
		std::cout << std::endl;
	}
	return 0;
}