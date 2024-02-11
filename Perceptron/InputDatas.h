#pragma once
#include <iostream>
#include <vector>

class InputDatas {
private:
	std::vector<std::vector<float>> andData;
	std::vector<std::vector<float>> orData;
	std::vector<std::vector<float>> xorData;
	std::vector<std::vector<float>> norData;
	std::vector<std::vector<float>> nandData;
	std::vector<std::vector<float>> exnorData;
	std::vector<std::vector<float>> logicalImplicationData;
	std::vector<std::vector<float>> doubleImplicationData;

public:
	int selectedDataIndex = 0;
	std::vector<std::vector<std::vector<float>>> dataContainer;
	std::vector<const char*> dataNames;

	InputDatas();
	~InputDatas();
	void IncraseSelectedDataIndex();
	void DecreaseSelectedDataIndex();
};

InputDatas::InputDatas() {
	andData = {
		{0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 1.0}
	};
	orData = {
		{0.0, 0.0, 0.0},
		{0.0, 1.0, 1.0},
		{1.0, 0.0, 1.0},
		{1.0, 1.0, 1.0}
	};
	xorData = {
		{0.0, 0.0, 0.0},
		{0.0, 1.0, 1.0},
		{1.0, 0.0, 1.0},
		{1.0, 1.0, 0.0}
	};
	norData = {
		{0.0, 0.0, 1.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 0.0}
	};
	nandData = {
		{0.0, 0.0, 1.0},
		{0.0, 1.0, 1.0},
		{1.0, 0.0, 1.0},
		{1.0, 1.0, 0.0}
	};
	exnorData = {
		{0.0, 0.0, 1.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 1.0}
	};
	logicalImplicationData = {
		{0.0, 0.0, 1.0},
		{0.0, 1.0, 1.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 1.0}
	};
	doubleImplicationData = {
		{0.0, 0.0, 1.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 1.0}
	};

	dataContainer = {
		andData,
		orData,
		xorData,
		norData,
		nandData,
		exnorData,
		logicalImplicationData,
		doubleImplicationData
	};
	dataNames = {
		"AND",
		"OR",
		"XOR",
		"NOR",
		"NAND",
		"EXNOR"
		"LOGICAL IMPL"
		"DOUBLE IMPL"
	};
}

InputDatas::~InputDatas() {

}

void InputDatas::IncraseSelectedDataIndex() {
	if (selectedDataIndex < dataContainer.size() - 1) {
		selectedDataIndex++;
	}
}

void InputDatas::DecreaseSelectedDataIndex() {
	if (selectedDataIndex > 0) {
		selectedDataIndex--;
	}
}