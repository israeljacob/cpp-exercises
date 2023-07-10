#include "Dog.h"
#include<random>

Dog::Dog(std::string name) : Animal(name)
{
	std::mt19937 engine(std::random_device{}());

	std::uniform_int_distribution<int> distribution(0, 3);
	set_dir(Direction(distribution(engine)));
	steps = 3;
}

void Dog::printDetails() const
{
	std::cout << "Animal ditails: " << std::endl << "    name: " << this->get_name() << std::endl << "    location:"
		<< std::endl << "        row: " << this->getLocation().row << std::endl << "        colomn: " << this->getLocation().colomn
		<< std::endl << "    Type: Dog" << std::endl;
}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::move()
{
	if (!get_is_movving())
	{
		set_is_moving(true);
		std::mt19937 engine(std::random_device{}());

		std::uniform_int_distribution<int> distribution(0, 3);
		set_dir(Direction(distribution(engine)));
		steps = 3;
	}
}

void Dog::step()
{
	if (get_is_movving())
	{
		Direction dir = this->get_dir();
		Location loc = this->getLocation();
		switch (dir)
		{
		case RIGHT:
			if (loc.colomn + steps <= 39 && loc.colomn + steps >= 0)
				this->set_loc(Location(loc.colomn + steps, loc.row));
			else if (loc.colomn + steps > 39)
			{
				this->set_loc(Location(36 + 39 - loc.colomn, loc.row));
				turnHorizontally();
			}
			break;
		case LEFT:
			if (loc.colomn - steps >= 0 && loc.colomn - steps <= 39)
				this->set_loc(Location(loc.colomn - steps, loc.row));
			else if (loc.colomn - steps < 0)
			{
				this->set_loc(Location(3 - loc.colomn, loc.row));
				turnHorizontally();
			}
			break;
		case UP:
			if (loc.row + steps <= 19 && loc.row + steps >= 0)
				this->set_loc(Location(loc.colomn, loc.row + steps));
			else if (loc.row + steps > 19)
			{
				this->set_loc(Location(loc.colomn, 16 + 19 - loc.row));
				turnVertically();
			}
			break;
		case DOWN:
			if (loc.row + steps <= 19 && loc.row + steps >= 0)
				this->set_loc(Location(loc.colomn, loc.row - steps));
			else if (loc.colomn - steps < 0)
			{
				this->set_loc(Location(loc.colomn, 3 - loc.row));
				turnVertically();
			}
			break;
		default:
			break;
		}
		if (steps == 3)
			steps = -1;
		else
			steps = 3;
	}
}


