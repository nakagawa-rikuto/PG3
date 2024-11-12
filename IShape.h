#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <numbers>
#include <stdio.h>

// Šî’êƒNƒ‰ƒX
class IShape {
public:

	IShape() = default;
	~IShape() = default;

	virtual void Size() = 0;
	virtual void Draw() = 0;
};

