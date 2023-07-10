#pragma once
#include<iostream>
#include<vector>
#include"Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Dog.h"
#include "Enums.h"
#include "Location.h"
class Zoo
{
private:
	std::vector<Animal*> list;
public:
	~Zoo();
	void run();
private:
	void stop(int animal_num);
	void move(int animal_num);
	void create(std::string animal_type, std::string animal_name);
	void del(int animal_num);
	void delAll(std::string animal_type);
	void step();
	void help();
};

