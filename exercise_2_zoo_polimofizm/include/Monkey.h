#include"Animal.h"
#pragma once
class Monkey : public Animal
{
public:
	Monkey(std::string name);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
};

