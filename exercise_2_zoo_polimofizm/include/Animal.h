#include <string>
#include"Location.h"
#include"Enums.h"
#pragma once
class Animal
{
private:
	std::string _name;
	Location _loc;
	bool _is_movving;
	Direction _dir;
public:
	Animal(std::string name);
	virtual ~Animal();

	virtual void printDetails() const = 0;
	virtual char getInitial() const = 0;
	virtual std::string get_name() const;
	virtual Location getLocation() const;
	virtual Direction get_dir() const;
	bool get_is_movving() const;
	void set_dir(Direction dir);
	void set_loc(Location loc);
	void set_is_moving(bool is_moving);
	virtual void step() = 0;
	void stop();
	virtual void move() = 0;
	virtual void turnVertically();
	void turnHorizontally();
};

#pragma once
