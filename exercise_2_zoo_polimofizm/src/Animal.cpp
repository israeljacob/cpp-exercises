#include "Animal.h"
#include "Location.h"

Animal::Animal(std::string name)
{
	_name = name;
	_loc = Location();
	_is_movving = true;
}

Animal::~Animal()
{
}

std::string Animal::get_name() const
{
	return _name;
}

Location Animal::getLocation() const
{
	return this->_loc;
}

Direction Animal::get_dir() const
{
	return _dir;
}

bool Animal::get_is_movving() const
{
	return _is_movving;
}

void Animal::set_dir(Direction dir)
{
	this->_dir = dir;
}

void Animal::set_loc(Location loc)
{
	_loc = loc;
}

void Animal::set_is_moving(bool is_moving)
{
	this->_is_movving = is_moving;
}

void Animal::stop()
{
	_is_movving = false;
}

void Animal::turnVertically()
{
	if (_dir == UP)
		_dir = DOWN;
	else if (_dir == DOWN)
		_dir = UP;
}

void Animal::turnHorizontally()
{
	if (_dir == RIGHT)
		_dir = LEFT;
	else if (_dir == LEFT)
		_dir = RIGHT;
}

