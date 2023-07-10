#include "Lion.h"
#include<random>
Lion::Lion(std::string name) : Animal(name)
{
	std::mt19937 engine(std::random_device{}());

	std::uniform_int_distribution<int> distribution(0, 1);
	set_dir(Direction(distribution(engine)));
}

void Lion::printDetails() const
{
	std::cout << "Animal ditails: " << std::endl << "    name: " << this->get_name() << std::endl << "    location:"
		<< std::endl << "        row: " << this->getLocation().row << std::endl << "        colomn: " << this->getLocation().colomn
		<< std::endl << "    Type: Lion" << std::endl;
}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::move()
{
	if (!get_is_movving())
	{
		this->set_is_moving(true);
		std::mt19937 engine(std::random_device{}());

		std::uniform_int_distribution<int> distribution(0, 1);
		set_dir(Direction(distribution(engine)));
	}
}

void Lion::step()
{
	if (get_is_movving())
	{
		Direction dir = this->get_dir();
		Location loc = this->getLocation();
		if (dir == RIGHT)
		{
			if (loc.colomn + 2 <= 39)
				this->set_loc(Location(loc.colomn + 2, loc.row));
			else
			{
				this->set_loc(Location(loc.colomn - 2 * (loc.colomn - 38), loc.row));
				turnHorizontally();
			}
		}
		else
		{
			if (loc.colomn - 2 >= 0)
				this->set_loc(Location(loc.colomn - 2, loc.row));
			else
			{
				this->set_loc(Location(2 - loc.colomn, loc.row));
				turnHorizontally();
			}
		}
	}
}

void Lion::turnVertically()
{
	return;
}

