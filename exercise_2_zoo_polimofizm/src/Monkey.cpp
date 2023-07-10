#include "Monkey.h"
#include <random>

Monkey::Monkey(std::string name) : Animal(name)
{
	std::mt19937 engine(std::random_device{}());

	std::uniform_int_distribution<int> distribution(0, 3);
	set_dir(Direction(distribution(engine)));
}

void Monkey::printDetails() const
{
	std::cout << "Animal ditails: " << std::endl << "    name: " << get_name() << std::endl << "    location:"
		<< std::endl << "        row: " << getLocation().row << std::endl << "        colomn: " << getLocation().colomn
		<< std::endl << "    Type: Monkey" << std::endl;
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::move()
{
	if (!get_is_movving())
	{
		set_is_moving(true);
		set_dir(Direction(rand() % 4));
	}
}

void Monkey::step()
{
	if (get_is_movving())
	{
		static int moves = 1;
		static int steps = rand() % 2 + 1;
		if (moves == 5)
		{
			set_dir(Direction(rand() % 4));
			steps = rand() % 2 + 1;
		}
		Direction dir = this->get_dir();
		Location loc = this->getLocation();
		switch (dir)
		{
		case RIGHT:
			if (loc.colomn + steps <= 39)
				this->set_loc(Location(loc.colomn + steps, loc.row));
			else
			{
				this->set_loc(Location(loc.colomn - steps * (loc.colomn - 38), loc.row));
				turnHorizontally();
			}
			break;
		case LEFT:
			if (loc.colomn - steps >= 0)
				this->set_loc(Location(loc.colomn - steps, loc.row));
			else
			{
				this->set_loc(Location(steps * (1 - loc.colomn), loc.row));
				turnHorizontally();
			}
			break;
		case UP:
			if (loc.row + steps <= 19)
				this->set_loc(Location(loc.colomn, loc.row + steps));
			else
			{
				this->set_loc(Location(loc.colomn, loc.row - steps * (loc.row - 18)));
				turnVertically();
			}
			break;
		case DOWN:
			if (loc.row - steps >= 0)
				this->set_loc(Location(loc.colomn, loc.row - steps));
			else
			{
				this->set_loc(Location(loc.colomn, steps * (1 - loc.row)));
				turnVertically();
			}
			break;
		default:
			break;
		}
		if (moves == 5)
			moves = 1;
		else
			moves++;
	}
}
