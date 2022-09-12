//N*N matrics, pow(A, B) (2 ¡Â N ¡Â  5, 1 ¡Â B ¡Â 100,000,000,000)
//vector form 0~N / 1*N+(0~N) / ~ / (N-1) + (0-N) 
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

std::vector<unsigned long long int> operator*(std::vector<unsigned long long int> v1, std::vector<unsigned long long  int> v2) {
	if (v1.size() != v2.size()) {
		return std::vector<unsigned long long  int>();
	}
	else {
		int n = std::sqrt(v1.size());

		std::vector<unsigned long long  int> result(n * n);

		for (int i = 0; i < n; i++) { // i Çà
			for (int j = 0; j < n; j++) { // j ¿­
				for (int k = 0; k < n; k++) {
					result[n * i + j] += v1[n * i + k] * v2[n * k + j];
				}
			}
		}

		return result;
	}
}

std::vector<unsigned long long  int> pow(std::vector<unsigned long long  int> v, int N) {
	if (N == 1) {
		return v;
	}
	else {
		if (N % 2 == 0) {
			std::vector<unsigned long long  int> r = pow(v, N/2);
			return r*r;
		}
		else {
			std::vector<unsigned long long  int> r = pow(v, N / 2);
			return r*r*v;
		}
	}
}

int main() {
	int N, B;
	std::cin >>N>>B;
	std::cin.ignore();

	std::vector<unsigned long long int> v;

	std::string str;
	std::stringstream ss;
	for (int i = 0; i < N; i++) {

		std::getline(std::cin, str);
		ss << str;
		str.clear();

		unsigned long long input;
		for (int j = 0; j < N; j++) {
			ss >> input;
			v.push_back(input);
		}

		ss.clear();
	}


	std::vector<unsigned long long  int> result = pow(v, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			std::cout << result[N * i + j]%1000 << " ";
		std::cout << std::endl;
	}

	return 0;
}