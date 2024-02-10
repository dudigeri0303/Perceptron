#pragma once
#include <iostream>
#include "raygui.h"
#include "raylib.h"
#include "Node.h"
#include "Weight.h"

class Perceptron{
private:
	int numberOfInputs;
	int x;
	int y;
	float radius;
	std::vector<Node*> inputNodes;
	std::vector<Weight*> weights;
	Node* outputNode;

	void FeedForward();
	void BackProp();
public:
	Perceptron(int numOfI, int x, int y);
	~Perceptron();
	void Update();
	void Draw();
};

Perceptron::Perceptron(int numOfI, int xVal, int yVal) : numberOfInputs(numOfI), x(xVal), y(yVal){
	radius = 30.0f;
	for (int i = 0; i < numberOfInputs; i++) {
		inputNodes.push_back(new Node(INPUT, 1.0f, 50, 250 + i*50));
		weights.push_back(new Weight());
	}
	outputNode = new Node(OUTPUT, 0.0f, 250, 275);
}

Perceptron::~Perceptron(){
	for (auto n : inputNodes) {
		delete n;
	}
	inputNodes.clear();
	for (auto w : weights) {
		delete w;
	}
	weights.clear();
	delete outputNode;
}

void Perceptron::FeedForward() {

}

void Perceptron::BackProp() {

}

void Perceptron::Update() {

}

void Perceptron::Draw() {
	for (int i = 0; i < weights.size(); i++) {
		weights[i]->Draw(inputNodes[i]->x, inputNodes[i]->y, x, y);
	}
	for (auto n : inputNodes) {
		n->Draw();
	}
	outputNode->Draw();
	DrawCircle(x, y, radius, RED);
}

