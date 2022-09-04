//12865
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int N, K; // N = stuff number, K = weight

struct Object {
	int weight;
	int value;

	Object(int weight, int value) : weight(weight), value(value) {}	
};

bool compare(Object obj1, Object obj2) {
	return obj1.weight > obj2.weight;
}

std::vector<int> valueCase;
Object ifYouChose(std::vector<Object> objs, int index, Object prevObj) {
	Object nowObj(prevObj.value, prevObj.weight);

	if (index > K - 1) {
		valueCase.push_back(nowObj.value);
		return nowObj;
	}

	nowObj.value += objs[index].value;
	nowObj.weight += objs[index].weight;

	if (nowObj.weight > K) {
		nowObj.value -= objs[index].value;
		nowObj.weight -= objs[index].weight;
		valueCase.push_back(nowObj.value);
		return nowObj;
	}
	else {
		if (index == objs.size()-1) {
			valueCase.push_back(nowObj.value);
			return nowObj;
		}
		else {
			for (int i = index + 1; i < objs.size(); i++) {
				if (i == objs.size() - 1) {
					nowObj.value += objs[i].value;
					nowObj.weight += objs[i].weight;
					if (nowObj.weight > K) {
						nowObj.value -= objs[i].value;
						nowObj.weight -= objs[i].weight;
					}
				}
				else {
					Object toPlus = ifYouChose(objs, i + 1, nowObj);
					nowObj.value += toPlus.value;
					nowObj.weight += toPlus.weight;
					if (nowObj.weight > K) {
						nowObj.value -= toPlus.value;
						nowObj.weight -= toPlus.weight;
						valueCase.push_back(nowObj.value);
					}
				}
			}
		}
	}

	valueCase.push_back(nowObj.value);
	return nowObj;
}

int main() {
	std::vector<Object> objects;

	std::string input;
	std::stringstream ss;

	std::getline(std::cin, input);

	ss << input;
	input.clear();
	ss >> N >> K;
	ss.clear();

	int weight, value;
	for (int i = 0; i < N; i++) {
		std::getline(std::cin, input);
		ss << input;
		input.clear();
		ss >> weight >> value;
		ss.clear();

		objects.push_back(Object(weight, value));
	}

	std::sort(objects.begin(), objects.end(), compare);

	ifYouChose(objects, 0, Object(0, 0));

	std::sort(valueCase.begin(), valueCase.end());

	for (auto i : valueCase)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}