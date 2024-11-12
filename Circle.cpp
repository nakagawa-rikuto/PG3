#include "Circle.h"

void Circle::Size() {

	answer_ = M_PI * radius_ * radius_;
}

void Circle::Draw() {

	printf("Circle %.2f\n", answer_);
}
