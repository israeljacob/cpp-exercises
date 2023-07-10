#include "Location.h"
#include <random>


Location::Location()
{
	std::mt19937 engine(std::random_device{}());

	std::uniform_int_distribution<int> distribution(0, 19);
	row = distribution(engine);

	std::uniform_int_distribution<int> distribution0(0, 39);
	colomn = distribution0(engine);
}

Location::Location(int colomn, int row)
{
	if (row <= 19 && row >= 0 && colomn <= 39 && colomn >= 0)
	{
		this->row = row;
		this->colomn = colomn;
	}
}

void Location::setRow(int row)
{
	if (row >= 0 && row <= 19)
		this->row = row;
}

void Location::setColomn(int colomn)
{
	if (colomn >= 0 && colomn <= 39)
		this->colomn = colomn;
}

Location Location::operator+=(Location other)
{
	return Location(this->row + other.row, this->colomn + other.colomn);
}

bool Location::operator==(Location other)
{
	return this->row == other.row && this->colomn == other.colomn;
}

bool Location::operator!=(Location other)
{
	return !(*this == other);
}

std::ostream& Location::operator<<(std::ostream& os)
{
	os << "Location{" << std::endl << "    row = " << this->row << std::endl << "    colomn = " << this->colomn << std::endl;
	return os;
}

