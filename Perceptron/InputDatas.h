#pragma once
#include <iostream>
#include <vector>

class InputDatas {
private:

public:
	std::vector<std::vector<float>> andData;

	InputDatas();
	~InputDatas();
	

};

InputDatas::InputDatas() {
	andData = {
		{0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 1.0}
	};
}

InputDatas::~InputDatas() {

}