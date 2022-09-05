<<<<<<< HEAD
//³»°¡ Â§ °Í vs ³²ÀÌ Â§ °Í https://cocoon1787.tistory.com/206
#include <iostream>
=======
//12865
#include <iostream>
#include <string>
>>>>>>> 643153f65f6bd9bf812f0be9966cb1348f86fca8
#include <sstream>
#include <vector>
#include <algorithm>

int N, K; // N = stuff number, K = weight

struct Object {
	int weight;
	int value;

<<<<<<< HEAD
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
=======
	Object(int weight, int value) : weight(weight), value(value) {}	
>>>>>>> 643153f65f6bd9bf812f0be9966cb1348f86fca8
};

bool compare(Object obj1, Object obj2) {
	return obj1.weight > obj2.weight;
}

<<<<<<< HEAD
 
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
=======
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
>>>>>>> 643153f65f6bd9bf812f0be9966cb1348f86fca8
}

int main() {
	std::vector<Object> objects;
<<<<<<< HEAD
=======

>>>>>>> 643153f65f6bd9bf812f0be9966cb1348f86fca8
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

<<<<<<< HEAD
		objects.push_back({ weight, value });
=======
		objects.push_back(Object(weight, value));
>>>>>>> 643153f65f6bd9bf812f0be9966cb1348f86fca8
	}

	std::sort(objects.begin(), objects.end(), compare);

<<<<<<< HEAD
	getValCase(objects, 0, {0,0});
	std::sort(valCase.begin(), valCase.end());

	std::cout << valCase.back();
=======
	ifYouChose(objects, 0, Object(0, 0));

	std::sort(valueCase.begin(), valueCase.end());

	for (auto i : valueCase)
		std::cout << i << " ";
	std::cout << std::endl;
>>>>>>> 643153f65f6bd9bf812f0be9966cb1348f86fca8

	return 0;
}