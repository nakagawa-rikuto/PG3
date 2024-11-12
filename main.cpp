#include "Circle.h"
#include "Rectangle.h"

#include <vector>
#include <memory>

int main() {

	std::vector<std::unique_ptr<IShape>> iShape_;
	iShape_.push_back(std::make_unique<Circle>());
	iShape_.push_back(std::make_unique<Rectangle>());

	for (const auto& IShape : iShape_) {
		IShape->Size();
		IShape->Draw();
	}

	return 0;
}