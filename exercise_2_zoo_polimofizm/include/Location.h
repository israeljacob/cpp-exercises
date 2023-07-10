#pragma once
#include <iostream>
struct Location
{
	int row;
	int colomn;
public:
	Location();
	Location(int row, int colomn);
	void setRow(int row);
	void setColomn(int colomn);
	Location operator+=(Location other);
	bool operator==(Location other);
	bool operator!=(Location other);
	std::ostream& operator<<(std::ostream& os);
};