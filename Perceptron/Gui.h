#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "Perceptron.h"
#include "InputDatas.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class Gui {
private:
	bool calculating = false;
	Perceptron* perceptron;
	InputDatas* inputDatas;
	
	void HandleAndDrawSartButton();
	void HandleAndDrawStopButton();
	void HandleInputChooser();
	
public:
	Gui();
	~Gui();
	void HandleGuiElements();
	void Update();
	void Draw();
};

Gui::Gui() {
	perceptron = new Perceptron(2, 150, 275);
	inputDatas = new InputDatas();
}

Gui::~Gui() {
	delete perceptron;
	delete inputDatas;
}

void Gui::HandleAndDrawSartButton() {
	if (GuiButton({ 210, 700, 50, 30 }, "Start!") && !calculating) {
		calculating = true;
	}
}

void Gui::HandleAndDrawStopButton() {
	if (GuiButton({ 210, 750, 50, 30 }, "Stop!") && calculating) {
		calculating = false;
	}
}

void Gui::HandleInputChooser() {
	if (GuiButton({ 490, 700, 70, 30 }, "Previous!") && !calculating) {
		inputDatas->DecreaseSelectedDataIndex();
	}

	GuiLabel({ 570, 700, 90, 30 }, inputDatas->dataNames[inputDatas->selectedDataIndex]);

	if (GuiButton({ 650, 700, 70, 30 }, "Next!") && !calculating) {
		inputDatas->IncraseSelectedDataIndex();
	}
}

void Gui::HandleGuiElements() {
	HandleAndDrawSartButton();
	HandleAndDrawStopButton();
	HandleInputChooser();
}

void Gui::Update() {
	if (calculating) {
		perceptron->Update(inputDatas->dataContainer[inputDatas->selectedDataIndex]);
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	}
}

void Gui::Draw() {
	perceptron->Draw();
}