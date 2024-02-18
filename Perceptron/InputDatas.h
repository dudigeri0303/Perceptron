#pragma once
#include <iostream>
#include <vector>

class InputDatas {
private:
	std::vector<std::vector<float>> andData;
	std::vector<std::vector<float>> orData;
	std::vector<std::vector<float>> norData;
	std::vector<std::vector<float>> nandData;
	std::vector<std::vector<float>> logicalImplicationData;

public:
	int selectedDataIndex = 0;
	std::vector<std::vector<std::vector<float>>> dataContainer;
	std::vector<const char*> dataNames;
	std::vector<Texture2D> gateTextures;

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
	logicalImplicationData = {
		{0.0, 0.0, 1.0},
		{0.0, 1.0, 1.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 1.0}
	};
	dataContainer = {
		andData,
		orData,
		norData,
		nandData,
		logicalImplicationData
	};
	dataNames = {
		"AND",
		"OR",
		"NOR",
		"NAND",
		"L.IMPL."
	};
	gateTextures = {
		LoadTexture("GateImages/andGate.png"),
		LoadTexture("GateImages/orGate.png"),
		LoadTexture("GateImages/norGate.png"),
		LoadTexture("GateImages/nandGate.png"),
		LoadTexture("GateImages/logicalImplGate.png")
	};
}

InputDatas::~InputDatas() {
	for (int i = 0; i < gateTextures.size(); i++) {
		UnloadTexture(gateTextures[i]);
	}
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