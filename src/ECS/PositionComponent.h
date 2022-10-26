#pragma once
#include "Components.h"

class PositionComponent : public Component {
public:
	PositionComponent() 
		: x_(0), y_(0) {}

	PositionComponent(int x, int y)
		: x_(x), y_(y) {}

	int x() { return x_; }
	int y() { return y_; }

	void SetPosition(int x, int y) {
		x_ = x;
		y_ = y;
	}

	void update() override {
		++x_;
		++y_;
	}

	void x(int x) { x_ = x; }
	void y(int y) { y_ = y; }

private:
	int x_;
	int y_;
};