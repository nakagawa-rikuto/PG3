#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	void Size()override;
	void Draw()override;
private:
	float width_ = 5.0f;
	float height_ = 6.0f;
	float answer_;
};

