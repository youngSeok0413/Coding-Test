#include <iostream>
#include <vector>

#define MOD 1000000

using namespace std;

vector<unsigned long long> matrix = 
	{1, 1, 
	1, 0};

vector<unsigned long long> operator*(vector<unsigned long long> m1, vector<unsigned long long> m2) {
	vector<unsigned long long> result(4);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[2 * i + j] += (m1[2*i +k] * m2[2 * k + j])%MOD;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		result[i] = result[i] % MOD;
	}

	return result;
}

vector<unsigned long long> pow(unsigned long long n) {
	if (n == 1) {
		return matrix;
	}
	else if (n%2 == 0) {
		vector<unsigned long long> half = pow(n/2);
		return half * half;
	}
	else {
		vector<unsigned long long> half = pow(n / 2);
		return half * half * matrix;
	}
}

int main() {
	int input;
	std::cin >> input;

	vector<unsigned long long> result = pow(input);

	std::cout << result[2];

	return 0;
}


/*
* #include<iostream>
 
long long a[1500050];
int INF = 1000000;
 
void fibonacci() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 0; i < 1500000; i++) {
        a[i + 2] = (a[i + 1] + a[i]) % INF;
    }
}
 
int main() {
    long long n;
    std::cin >> n;
    fibonacci();
    std::cout << a[n%1500000] << "\n";
 
}
*/