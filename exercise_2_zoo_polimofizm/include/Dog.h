#pragma once
#include "Animal.h"
class Dog : public Animal
{
private:
	int steps;
public:
	Dog(std::string name);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
};

