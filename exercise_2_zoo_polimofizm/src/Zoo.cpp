#include "Zoo.h"

Zoo::~Zoo()
{
	for (size_t i = 0; i < list.size(); i++)
		delete list[i];
}

void Zoo::run()
{
	list.push_back(new Lion("Simba"));
	list.push_back(new Lion("Mufasa"));
	list.push_back(new Monkey("Rafiki"));
	list.push_back(new Dog("Toto"));

	int choice;
	int animal_num;
	std::string animal_type;
	std::string animal_name;
	do
	{
		std::cout << "The zoo map:" << std::endl;
		std::cout << "  ";
		for (size_t i = 1; i <= 9; i++)
		{
			std::cout << i << "  ";
		}
		for (size_t i = 10; i <= 40; i++)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		for (size_t i = 0; i <= 19; i++)
		{
			std::cout << i + 1 << " ";
			if (i <= 9)
				std::cout << " ";
			for (size_t j = 0; j <= 39; j++)
			{
				for (size_t k = 0; k < list.size(); k++)
				{
					if (list[k]->getLocation().row == i && list[k]->getLocation().colomn == j)
					{
						std::cout << list[k]->getInitial() << "  ";
						break;
					}
				}
				std::cout << "   ";
			}
			std::cout << std::endl;
		}
		for (size_t i = 0; i < list.size(); i++)
		{
			std::cout << "Animal number " << i + 1 << ":" << std::endl;
			list[i]->printDetails();
			std::cout << std::endl;
		}
		std::cout << "Commands list - To implement a command, enter its number:" << std::endl << "0: exit" << std::endl
			<< "1: stop" << std::endl << "2: move" << std::endl << "3: create" << std::endl << "4: delete" << std::endl
			<< "5: delete all" << std::endl << "6: ." << std::endl << "7: help" << std::endl << std::endl
			<< "Please enter a number betueen 0 - 7." << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case STOP:
			std::cout << "Enter the animal number." << std::endl;
			std::cin >> animal_num;
			stop(animal_num);
			break;
		case MOVE:
			std::cout << "Enter the animal number." << std::endl;
			std::cin >> animal_num;
			move(animal_num);
			break;
		case CREATE:
			std::cout << "Enter the animal type (Lion, Monkey or Dog)." << std::endl;
			std::cin >> animal_type;
			std::cout << "Enter the animal name." << std::endl;
			std::cin >> animal_name;
			create(animal_type, animal_name);
			break;
		case DEL:
			std::cout << "Enter the animal number." << std::endl;
			std::cin >> animal_num;
			del(animal_num);
			break;
		case DELALL:
			std::cout << "Enter the animal type (Lion, Monkey or Dog)." << std::endl;
			std::cin >> animal_type;
			delAll(animal_type);
			break;
		case DOT:
			step();
			break;
		default:
			std::cout << "Incorrct number.Try again" << std::endl;
			break;
		}
	} while (choice);
}

void Zoo::stop(int animal_num)
{
	if (animal_num <= list.size())
		list[animal_num - 1]->stop();
}

void Zoo::move(int animal_num)
{
	if (animal_num <= list.size())
		list[animal_num - 1]->move();
}

void Zoo::create(std::string animal_type, std::string animal_name)
{
	if (animal_type == "Lion" || animal_type == "lion")
		list.push_back(new Lion(animal_name));
	else if (animal_type == "Monkey" || animal_type == "monkey")
		list.push_back(new Monkey(animal_name));
	else if (animal_type == "Dog" || animal_type == "dog")
		list.push_back(new Dog(animal_name));
}

void Zoo::del(int animal_num)
{
	if (animal_num <= list.size())
		list.erase(list.begin() + animal_num - 1);
}

void Zoo::delAll(std::string animal_type)
{
	for (size_t i = 0; i < list.size(); i++)
		list.erase(list.begin() + i);	
}

void Zoo::step()
{
	for (size_t i = 0; i < list.size(); i++)
		list[i]->step();
}

void Zoo::help()
{
	std::cout << "Below are the details of the commands:" << std::endl
		<< "Stop: The command will receive as a parameter the number of the animal and will make the animal stop." << std::endl
		<< "Move: The command will receive as a parameter the number of the animal and will make the animal move." << std::endl
		<< "Create: The command accepts as parameters the type of animal and a name for it"
		<< " and will add a new animal from type that was given with the name that was given, to the list." << std::endl
		<< "Delete: The command will receive as a parameter the number of the animal and will delete the animal from the list"
		<< std::endl
		<< "Delete all: The command will receive as a parameter the type of animal"
		<< "and will delete from the list all animals of this type (if they exist)." << std::endl
		<< ". - dot: This command will be used to make the program advance to the next line, without changing anything."
		<< "That is, every animals in the motion will continue to move according to the rules." << std::endl
		<< "Exit: leaving the program." << std::endl;
}

