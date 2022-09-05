//³»°¡ Â§ °Í vs ³²ÀÌ Â§ °Í https://cocoon1787.tistory.com/206
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int N, K; // N = stuff number, K = weight

struct Object {
	int weight;
	int value;

	Object(int weight, int value) : weight(weight), value(value) {}

	Object operator+=(Object obj) {
		return Object(weight+obj.weight, value+obj.value);
	}

	Object operator-=(Object obj) {
		return Object(weight - obj.weight, value - obj.value);
	}

	bool operator==(Object obj) {
		return weight == obj.weight && value == obj.value;
	}

	bool operator!=(Object obj) {
		return weight != obj.weight && value == obj.value;
	}
};

bool compare(Object obj1, Object obj2) {
	return obj1.weight > obj2.weight;
}

 
Object whetherAbleToInsert(const std::vector<Object>& objects, int index, Object prevState) {
	return ((prevState.weight + objects[index].weight) > K) ? prevState : 
		Object(prevState.weight + objects[index].weight, prevState.value + objects[index].value);
}

std::vector<int> valCase;

void getValCase(const std::vector<Object>& objects, int index, Object prevState) {
	if (index > objects.size()-1) {
		return;
	}
	else if (prevState.weight + objects[objects.size()-1].weight > K) {
		valCase.push_back(prevState.value);
	}
	else if (index == objects.size()-1) {
		Object inserted = whetherAbleToInsert(objects, index, prevState);
		if (inserted == prevState) {
			valCase.push_back(prevState.value);
		}
		else {
			valCase.push_back(inserted.value);
			valCase.push_back(prevState.value);
		}
	}
	else {
		Object inserted = whetherAbleToInsert(objects, index, prevState);
		if(inserted == prevState) {
			getValCase(objects, index+1, prevState);
		}
		else {
			getValCase(objects, index+1, prevState);
			getValCase(objects, index+1, inserted);
		}
	}
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

		objects.push_back({ weight, value });
	}

	std::sort(objects.begin(), objects.end(), compare);

	getValCase(objects, 0, {0,0});
	std::sort(valCase.begin(), valCase.end());

	std::cout << valCase.back();

	return 0;
}