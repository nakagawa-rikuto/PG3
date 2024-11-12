#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <numbers>
#include <stdio.h>

// ���N���X
class IShape {
public:

	IShape() = default;
	~IShape() = default;

	virtual void Size() = 0;
	virtual void Draw() = 0;
};

