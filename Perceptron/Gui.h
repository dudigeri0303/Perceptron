#pragma once
#include <iostream>
#include "Perceptron.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class Gui {
private:
	Perceptron* perceptron;

public:
	Gui();
	~Gui();
	void Update();
	void Draw();
};

Gui::Gui() {
	perceptron = new Perceptron(2, 150, 275);
}

Gui::~Gui() {
	delete perceptron;
}

void Gui::Update() {
	perceptron->Update();
}

void Gui::Draw() {
	perceptron->Draw();
}