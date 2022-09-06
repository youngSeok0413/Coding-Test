/*
#include <iostream>
long long int DP[40000000] = {-1, };

long long int factorial(int n) {
	if (n == 0) {
		DP[n] = 1;
		return 1;
	}
	else if (DP[n]!=0) {
		return DP[n];
	}
	else {
		DP[n] = factorial(n - 1) * n;
		return DP[n];
	}
}

int main() {
	int N, K;
	std::cin >> N >> K;
	
	factorial(N);

	std::cout << (DP[N]/(DP[K]* DP[N-K]))%1000000007;

	return 0;
}
*/

/*
#include <iostream>
unsigned long long int DP[40000000] = {0, };

unsigned long long int getBiCo(unsigned long long int n, unsigned long long int k) {
	if (k == 0) {
		DP[k] = 1;
		return 1;
	}
	else if (DP[k]!= 0) {
		return DP[k];
	}
	else {
		DP[k] = getBiCo(n, k-1)*(n-k+1)/k;
		return DP[k];
	}
}

int main() {
	int N, K;
	std::cin >> N >> K;

	std::cout << getBiCo(N, K) % 1000000007;

	return 0;
}
*/

/* 페르마의 
소정리를 이용하는 방법
*/

#include <iostream>
#include <cmath>

unsigned long long N, K, A, B, half;
unsigned long long mod = 1000000007;

unsigned long long solve(unsigned long long int x) {
	if (x == 0) return 1;
	if (x % 2 == 1) return B * solve(x - 1) % mod;
	else {
		half = solve(x/2);
		return half * half % mod;
	}
}

int main() {

	std::cin >> N >> K;
	A = 1;
	for (int i = N; i >= N - K + 1; i--)A = (A * i) % mod;
	B = 1;
	for (int i = 1; i <= K; i++) B = (B * i) % mod;

	B = solve(mod-2);

	std::cout << A * B % mod;

	return 0;
}