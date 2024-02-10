#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "raylib.h"

enum NodeType {
    INPUT,
    OUTPUT
};

class Node {
private:
    float radius;

public:
    NodeType type;
    int x;
    int y;
    float value;

    Node(NodeType nType, float val, int x, int y);
    ~Node();
    void Update();
    void Draw();
};

Node::Node(NodeType nType, float val, int xVal, int yVal) :type(nType), value(val), x(xVal), y(yVal) {
    radius = 10.0f;
}

Node::~Node() {

}

void Node::Update() {

}

void Node::Draw() {
    DrawCircle(x, y, radius, BLACK);
    DrawText(std::to_string(value).c_str(), x - (int)radius - 10, y - (int)radius - 15, 14, BLACK);
}