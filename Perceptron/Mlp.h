#pragma once
#include <random>
#include "Perceptron.h"
#include "Node.h"

class Mlp {
private:
	int numberOfInputs = 2;
	int desiredOutput = 0;
	float threshold = 0.5f;
	float error = 0.0f;
	float learningRate = 0.005f;
	float sigmoidResult = 0.0f;
	std::vector<Node*> inputNodes;
	Node* outputNode;
	std::vector<Perceptron*> perceptrons;
	//Perceptron* perceptron2;

	void FeedInputs(std::vector<std::vector<float>> inputDatas);
	void FeedForward();
	void ActivationFunction();
	void CalculateError();
	void BackProp();

public:
	Mlp();
	~Mlp();
	void Update(std::vector<std::vector<float>> inputDatas);
	void Draw();

};

Mlp::Mlp() {
	for (int i = 0; i < numberOfInputs + 1; i++) {
		inputNodes.push_back(new Node(1.0f, 50,  50 + i * 200));
	}
	outputNode = new Node(0.0f, 500, 275);

	perceptrons = {
		new Perceptron(3, 300, 150),
		new Perceptron(3, 300, 350)
	};
}

Mlp::~Mlp() {
	for (auto p : perceptrons) {
		delete p;
	}
	perceptrons.clear();
	for (auto n : inputNodes) {
		delete n;
	}
	delete outputNode;
	inputNodes.clear();
}

void Mlp::FeedInputs(std::vector<std::vector<float>> inputDatas) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, inputDatas.size() - 1);
	std::vector<float> data = inputDatas[dist6(rng)];
	inputNodes[0]->value = data[0];
	inputNodes[1]->value = data[1];
	desiredOutput = data[2];
}

void Mlp::FeedForward() {
	outputNode->value = 0.0f;
	for (auto p : perceptrons) {
		outputNode->value += p->FeedForward(inputNodes);
	}
}

void Mlp::ActivationFunction() {
	outputNode->value = 1.0f / (1.0f + std::exp(-1 * outputNode->value));
	sigmoidResult = outputNode->value;
	outputNode->value = outputNode->value >= threshold ? 1.0f : 0.0f;
}

void Mlp::CalculateError() {
	error = desiredOutput - outputNode->value;
}

void Mlp::BackProp() {
	for (auto p : perceptrons) {
		p->BackProp(inputNodes, learningRate, error, sigmoidResult);
	}
}

void Mlp::Update(std::vector<std::vector<float>> inputDatas) {
	FeedInputs(inputDatas);
	FeedForward();
	ActivationFunction();
	CalculateError();
	BackProp();
}

void Mlp::Draw() {
	for (auto p : perceptrons) {
		DrawLine(outputNode->x, outputNode->y, p->x, p->y, BLACK);
		p->Draw(inputNodes);
	}
	for (auto n : inputNodes) {
		n->Draw();
	}
	outputNode->Draw();
}


