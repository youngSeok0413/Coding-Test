#include <iostream>
#include <chrono>

/*Divide&Conquer
* �״�� �ذ��� �� ���� ������ ���Ͽ� ���� ������ �����Ͽ� ������ �ذ��ϴ� ���
* Sort Algorithm, FFT Algorithm�� ��ǥ���� ���̴�
* ���� ��� ȣ��� ������ �Լ��� ������� �߻��� Ȯ���� �ִ�.
* 
*/

unsigned long int howLong(long double (* fptr)(long double, int), long double num, int exp) {
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	fptr(num, exp);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::nanoseconds nano = end - start;
	return nano.count();
}

//recursion version
long double pow_v1(long double num, int exp) {
	if (exp == 0) {
		return 1;
	}
	else if (exp == 1) {
		return num;
	}
	if (exp % 2 == 0) {
		long double ans = pow_v1(num, exp / 2);
		return ans*ans;
	}
	else {
		long double ans = pow_v1(num, exp / 2);
		return ans*ans*num;
	}
}

//just recursion
long double pow_v2(long double num, int exp) {
	if (exp == 1) {
		return num;
	}
	if (exp == 0) {
		return 1;
	}
	return pow_v2(num, exp - 1) * num;
}
//simple repeatation
long double pow_v3(long double num, int exp) {
	if (exp == 0) {
		return 1;
	}
	else {
		long double result = 1;
		for (int i = 0; i < exp; i++)
			result *= num;
		return result;
	}
}
//dynamic programming
long double DP[292311] = { 0, };
long double pow_v4(long double num, int exp) {
	if (exp == 1) {
		return num;
	}
	else if (exp == 0) {
		return 1;
	}
	else if (DP[exp] != 0) {
		return DP[exp];
	}
	else {
		DP[exp] = pow_v4(num, exp-1) * num;
		return DP[exp];
	}
}

int main() {
	//D&C
	std::cout <<"1.0000001, 292 : " << pow_v1(1.0000001, 292) << " Time : " << howLong(pow_v1, 1.0000001, 292)<< "ns" << std::endl;
	//Recursion
	std::cout <<"1.0000001, 292 : " << pow_v2(1.0000001, 292) << " Time : " << howLong(pow_v2, 1.0000001, 292) << "ns" << std::endl;
	//Just Repeatation
	std::cout <<"1.0000001, 292 : " << pow_v3(1.0000001, 292) << " Time : " << howLong(pow_v3, 1.0000001, 292) << "ns" << std::endl;
	//Dynamic Programming
	std::cout << "1.0000001, 292 : " << pow_v4(1.0000001, 292) << " Time : " << howLong(pow_v4, 1.0000001, 292) << "ns" << std::endl;
	return 0;
}