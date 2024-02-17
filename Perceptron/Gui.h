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
	float delay = 0.0f;
	float delaySliderValue = 0.0f;
	Perceptron* perceptron;
	InputDatas* inputDatas;
	
	void HandleAndDrawSartButton();
	void HandleAndDrawStopButton();
	void HandleAndDrawDelaySlider();
	void HandleInputChooser();
	
public:
	Gui();
	~Gui();
	void HandleGuiElements();
	void Update();
	void Draw();
};

Gui::Gui() {
	perceptron = new Perceptron(2, 350, 250);
	inputDatas = new InputDatas();
}

Gui::~Gui() {
	delete perceptron;
	delete inputDatas;
}

void Gui::HandleAndDrawSartButton() {
	if (GuiButton({ 50, 500, 50, 30 }, "Start!") && !calculating) {
		calculating = true;
	}
}

void Gui::HandleAndDrawStopButton() {
	if (GuiButton({ 50, 550, 50, 30 }, "Stop!") && calculating) {
		calculating = false;
	}
}

void Gui::HandleAndDrawDelaySlider() {
	if (GuiSlider({ 150, 550, 170, 30 }, "Delay", NULL, &delaySliderValue, 0.0f, 500.0f)) {
		delay = delaySliderValue;
	}
}

void Gui::HandleInputChooser() {
	if (GuiButton({ 110, 500, 70, 30 }, "Previous!") && !calculating) {
		inputDatas->DecreaseSelectedDataIndex();
	}

	GuiLabel({ 180, 500, 90, 30 }, inputDatas->dataNames[inputDatas->selectedDataIndex]);

	if (GuiButton({ 250, 500, 70, 30 }, "Next!") && !calculating) {
		inputDatas->IncraseSelectedDataIndex();
	}
}

void Gui::HandleGuiElements() {
	HandleAndDrawSartButton();
	HandleAndDrawStopButton();
	HandleAndDrawDelaySlider();
	HandleInputChooser();
}

void Gui::Update() {
	if (calculating) {
		perceptron->Update(inputDatas->dataContainer[inputDatas->selectedDataIndex]);
		std::this_thread::sleep_for(std::chrono::milliseconds((int)delay));
	}
}

void Gui::Draw() {
	perceptron->Draw();
	DrawTexture(inputDatas->gateTextures[inputDatas->selectedDataIndex], 450, 450, WHITE);
}