#include <stdio.h>
#include <vector>

#include "Dog.h"
#include "Cat.h"

int main() {

	std::vector<std::unique_ptr<Animal>> animal_;
	animal_.push_back(std::make_unique<Dog>());
	animal_.push_back(std::make_unique<Cat>());

	for (const auto& animal : animal_) {
		animal->Voice();
	}

	return 0;
}