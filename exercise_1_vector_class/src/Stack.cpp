#include "Stack.h"
#include "Vector.h"

// Constructor: creates a stack with given size and initializes each element with a given value
explicit Stack::Stack(size_t size, int value)
{
	my_stack = Vector(size, value);
}

// Copy constructor: creates a new stack with the same elements as another stack
Stack::Stack(const Stack& other)
{
	this->my_stack = other.my_stack;
}

// Assignment operator: assigns the elements of another stack to this stack
Stack Stack::operator=(const Stack& other)
{
	this->my_stack = other.my_stack;
	return *this;
}

// Pushes a new element onto the stack
void Stack::push(const int value)
{
	this->my_stack.push_back(value);
}

// Pops an element off the top of the stack
void Stack::pop()
{
	this->my_stack.pop_back();
}

// Checks if the stack is empty
bool Stack::is_empty()
{
	return this->my_stack.empty();
}

// Equality operator: checks if two stacks have the same elements
bool Stack::operator==(const Stack& other)
{
	return this->my_stack == other.my_stack;
}

// Inequality operator: checks if two stacks have different elements
bool Stack::operator!=(const Stack& other)
{
	return this->my_stack != other.my_stack;
}

// Greater-than operator: checks if this stack has more elements than another stack
bool Stack::operator>(const Stack& other)
{
	return this->my_stack.size() > other.my_stack.size();
}

// Less-than operator: checks if this stack has fewer elements than another stack
bool Stack::operator<(const Stack& other)
{
	return this->my_stack.size() < other.my_stack.size();
}

// Compound assignment operator: adds a number to each element in the stack
Stack Stack::operator+=(const int number)
{
	int* pointer = this->my_stack.data();
	for (size_t i = 0; i < this->my_stack.size(); i++)
	{
		pointer[i] += number;
	}
	return *this;
}

// Compound assignment operator: subtracts a number from each element in the stack
Stack Stack::operator-=(const int number)
{
	int* pointer = this->my_stack.data();
	for (size_t i = 0; i < this->my_stack.size(); i++)
	{
		pointer[i] -= number;
	}
	return *this;
}

// Compound assignment operator: multiplies each element in the stack by a number
Stack Stack::operator*=(const int number)
{
	int* pointer = this->my_stack.data();
	for (size_t i = 0; i < this->my_stack.size(); i++)
	{
		pointer[i] *= number;
	}
	return *this;
}

// Compound assignment operator: divides each element in the stack by a number
Stack Stack::operator/=(const int number)
{
	int* pointer = this->my_stack.data();
	for (size_t i = 0; i < this->my_stack.size(); i++)
	{
		pointer[i] /= number;
	}
	return *this;
}

// Adds two Stacks together and returns the result as a new Stack
Stack Stack::operator+(Stack& other)
{
	int this_size = this->my_stack.size();
	int other_size = other.my_stack.size();
	Stack result = Stack(this_size + other_size);
	int* this_pointer = this->my_stack.data();
	int* other_pointer = other.my_stack.data();
	int* result_pointer = result.my_stack.data();
	for (size_t i = 0; i < this_size; i++)
	{
		result_pointer[i] = this_pointer[i];
	}
	for (size_t i = this_size, j = 0;i< this_size + other_size, j < other_size; i++)
	{
		result_pointer[i] = other_pointer[j];
	}
	return result;
}

// Adds another Stack to the current Stack and returns the modified current Stack
Stack Stack::operator+=(Stack& other)
{
	int this_size = this->my_stack.size();
	int other_size = other.my_stack.size();
	this->my_stack.resize(this_size + other_size, 0);
	int* this_pointer = this->my_stack.data();
	int* other_pointer = other.my_stack.data();
	for (size_t i = this_size, j = 0; i < this_size + other_size, j < other_size; i++)
	{
		this_pointer[i] = other_pointer[j];
	}
	return *this;
}



