#pragma once

#include "Animal.h"

class Dog : public Animal{
public:
	void Voice() const override;
};

