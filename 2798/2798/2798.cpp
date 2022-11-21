#include <iostream>

int main() {
	int N, M;
	int* deck;

	std::cin >> N >> M;
	deck = new int[N];
	for (int i = 0; i < N; i++) std::cin >> deck[i];

	int best = 0;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i+1; j < N - 1; j++) {
			for (int k = j+1; k < N; k++) {
				best = (deck[i] + deck[j] + deck[k] > best)&& (deck[i] + deck[j] + deck[k] <= M) ? deck[i] + deck[j] + deck[k] : best;
			}
		}
	}

	std::cout << best;

	return 0;
}