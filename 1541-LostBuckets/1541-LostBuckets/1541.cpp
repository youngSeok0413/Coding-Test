#include <iostream>
#include <string>

int main() {
	std::string formula;
	std::string num;

	int total = 0;

	std::getline(std::cin, formula);
	std::cin.clear();

	int plusOrMinus = 1;

	for (std::string::iterator iter = formula.begin(); iter < formula.end(); iter++) {
		if (iter == formula.begin()) {
			if (*iter == '-') {
				plusOrMinus = -1;
			}
			else if (*iter == '+') {
				plusOrMinus = 1;
			}
			else {
				if (iter != formula.end() - 1) {
					std::string::iterator next = iter+1;
					if (*next == '+'|| *next == '-') {
						num.push_back(*iter);
						total += std::stoi(num)*plusOrMinus;
						num.clear();
					}
					else {
						num.push_back(*iter);
					}
				}
				else {
					num.push_back(*iter);
					total += std::stoi(num) * plusOrMinus;
				}
			}
		}
		else if (iter == formula.end()-1) {
			if (*iter != '+' && *iter != '-') {
				if (*iter == '0') {
					num.push_back(*iter);
				}
				else if (*iter == '1') {
					num.push_back(*iter);
				}
				else if (*iter == '2') {
					num.push_back(*iter);
				}
				else if (*iter == '3') {
					num.push_back(*iter);
				}
				else if (*iter == '4') {
					num.push_back(*iter);
				}
				else if (*iter == '5') {
					num.push_back(*iter);
				}
				else if (*iter == '6') {
					num.push_back(*iter);
				}
				else if (*iter == '7') {
					num.push_back(*iter);
				}
				else if (*iter == '8') {
					num.push_back(*iter);
				}
				else if (*iter == '9') {
					num.push_back(*iter);
				}
				else {
					return 0;
				}
				total += std::stoi(num) * plusOrMinus;
				num.clear();
			}
			else {
				//error
				return 0;
			}
		}
		else {
			if (*iter == '+') {
				total += std::stoi(num)*plusOrMinus;
				num.clear();
			}
			else if (*iter == '-') {
				total += std::stoi(num) * plusOrMinus;
				num.clear();
				if (plusOrMinus == 1) {
					plusOrMinus = -1;
				}
			}
			else {
				if (*iter == '0') {
					num.push_back(*iter);
				}
				else if (*iter == '1') {
					num.push_back(*iter);
				}
				else if (*iter == '2') {
					num.push_back(*iter);
				}
				else if (*iter == '3') {
					num.push_back(*iter);
				}
				else if (*iter == '4') {
					num.push_back(*iter);
				}
				else if (*iter == '5') {
					num.push_back(*iter);
				}
				else if (*iter == '6') {
					num.push_back(*iter);
				}
				else if (*iter == '7') {
					num.push_back(*iter);
				}
				else if (*iter == '8') {
					num.push_back(*iter);
				}
				else if (*iter == '9') {
					num.push_back(*iter);
				}
				else {
					return 0;
				}
			}
		}
	}

	std::cout << total << std::endl;

	return 0;
}