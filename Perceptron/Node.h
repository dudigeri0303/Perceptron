#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "raylib.h"

class Node {
private:
    float radius;

public:
    int x;
    int y;
    float value;

    Node(float val, int x, int y);
    ~Node();
    void Draw();
};

Node::Node(float val, int xVal, int yVal) :value(val), x(xVal), y(yVal) {
    radius = 10.0f;
}

Node::~Node() {
}

void Node::Draw() {
    DrawCircle(x, y, radius, BLACK);
    DrawText(std::to_string(value).c_str(), x - (int)radius - 10, y - (int)radius - 15, 18, BLACK);
}