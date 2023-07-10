#include"Animal.h"
#pragma once
class Lion : public Animal
{
public:
	Lion(std::string name);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
	void turnVertically() override;
};

