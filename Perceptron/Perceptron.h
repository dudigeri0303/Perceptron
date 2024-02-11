#pragma once
#include <iostream>
#include <random>
#include <cmath>
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
	//VARIABLES FOR CALCULATIONS
	int desiredOutput = 0;
	float threshold = 0.5f;
	float error = 0.0f;
	float learningRate = 0.01f;
	float sigmoidResult = 0.0f;
	//pointers
	std::vector<Node*> inputNodes;
	std::vector<Weight*> weights;
	Node* outputNode;
	//InputDatas* inputDatas;

	void FeedInputs(std::vector<std::vector<float>> inputDatas);
	void FeedForward();
	void ActivationFunction();
	void CalculateError();
	void BackProp();
public:
	Perceptron(int numOfI, int x, int y);
	~Perceptron();
	void Update(std::vector<std::vector<float>> inputDatas);
	void Draw();
};

Perceptron::Perceptron(int numOfI, int xVal, int yVal) : numberOfInputs(numOfI), x(xVal), y(yVal){
	radius = 30.0f;

	for (int i = 0; i < numberOfInputs; i++) {
		inputNodes.push_back(new Node(INPUT, 1.0f, 50, 250 + i*50));
		weights.push_back(new Weight());
	}
	
	inputNodes.push_back(new Node(INPUT, 1.0f, 50, 250 + inputNodes.size() * 50));
	weights.push_back(new Weight());
	
	outputNode = new Node(OUTPUT, 0.0f, 250, 275);
	//inputDatas = new InputDatas();
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
	//delete inputDatas;
}

void Perceptron::FeedInputs(std::vector<std::vector<float>> inputDatas) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, inputDatas.size() - 1);
	std::vector<float> data = inputDatas[dist6(rng)];
	inputNodes[0]->value = data[0];
	inputNodes[1]->value = data[1];
	desiredOutput = data[2];
}

void Perceptron::FeedForward() {
	float outputValue = 0.0f;
	for (int i = 0; i < inputNodes.size(); i++) {
		outputValue += inputNodes[i]->value * weights[i]->value;
	}
	outputNode->value = outputValue;
}

void Perceptron::ActivationFunction() {
	outputNode->value = 1.0f / (1.0f + std::exp(-1 * outputNode->value));
	sigmoidResult = outputNode->value;
	outputNode->value = outputNode->value >= threshold ? 1.0f : 0.0f;
}

void Perceptron::CalculateError() {
	error = desiredOutput - outputNode->value;
}

void Perceptron::BackProp() {
	for (int i = 0; i < inputNodes.size(); i++) {
		weights[i]->value -= learningRate * ((2 * error) * -1 * (sigmoidResult * (1 - sigmoidResult)) * inputNodes[i]->value);
		//std::cout << "KUTYAFASZA" << std::endl;
		//std::cout<< i << "-" << weights[i]->value << std::endl;
	}
	std::cout << "output: " << outputNode->value << std::endl;
	std::cout << "Doutput: " << desiredOutput << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;
}

void Perceptron::Update(std::vector<std::vector<float>> inputDatas) {
	FeedInputs(inputDatas);
	FeedForward();
	ActivationFunction();
	CalculateError();
	BackProp();
}

void Perceptron::Draw() {
	DrawLine(outputNode->x, outputNode->y, x, y, BLACK);
	for (int i = 0; i < weights.size(); i++) {
		weights[i]->Draw(inputNodes[i]->x, inputNodes[i]->y, x, y);
	}
	for (auto n : inputNodes) {
		n->Draw();
	}
	outputNode->Draw();
	DrawCircle(x, y, radius, RED);
}

