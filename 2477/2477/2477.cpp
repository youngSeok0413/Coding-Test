#include <iostream>

void init(int N, char** plat) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			plat[i][j] = '*';
		}
	}
}

void draw(int N, char** plat) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << plat[i][j];
		}
		std::cout << '\n';
	}
}

void punch(int startX, int startY, int size, char** plat) {
	if (plat == nullptr) {
		return;
	}
	else if (size%3!=0) {
		return;
	}
	else if (size==3) {
		plat[startX+1][startY+1] = ' ';
		return;
	}
	else {
		int blankSize = size/3;
		for (int i = startX + blankSize; i < (startX + 2 * blankSize); i++) {
			for (int j = startY + blankSize; j < (startY + 2 * blankSize); j++) {
				plat[i][j] = ' ';
			}
		}
	}
}

void pattern(int size, char** plat, int platSize) {
	if (size%3!=0) {
		return;
	}
	else{
		
		for (int i = 0; i < platSize; i+=size) {
			for (int j = 0; j < platSize; j += size) {
				punch(i, j, size, plat);
			}
		}

		pattern(size/3, plat, platSize);
	}
}

int main() {
	int N;
	std::cin >> N;

	char** plat = (char**)malloc(sizeof(char*)*N);
	for (int i = 0; i < N; i++) {
		plat[i] = (char*)malloc(sizeof(char) * N);
	}

	init(N, plat);
	pattern(N, plat, N);
	draw(N, plat);

	for (int i = 0; i < N; i++) {
		free(plat[i]);
	}
	free(plat);

	return 0;
}