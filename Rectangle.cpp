#include "Rectangle.h"

void Rectangle::Size() {
	answer_ = width_ * height_;
}

void Rectangle::Draw() {
	printf("Rectangle %.2f\n", answer_);
}
