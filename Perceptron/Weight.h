#include <iostream>
#include <random>

class Weight {
private:

public:
	float value;
	
	Weight();
	~Weight();
	void Draw(int x1, int y1, int x2, int y2);
};

Weight::Weight(){
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<float> dis(0.0f, 1.0f);
	value = dis(rng);
}

Weight::~Weight() {

}

void Weight::Draw(int x1, int y1, int x2, int y2) {
	DrawLine(x1, y1, x2, y2, BLACK);
}