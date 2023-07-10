#pragma once
#include "Vector.h"

class Stack
{
	Vector my_stack; // a private member variable of type Vector for storing stack elements

public:
	// Constructor that takes the size of the stack and the initial value to fill the stack with
	explicit Stack(size_t, int);

	// Copy constructor
	Stack(const Stack& other);

	// Copy assignment operator
	Stack operator=(const Stack& other);

	// Pushes an element onto the top of the stack
	void push(const int value);

	// Removes the top element from the stack
	void pop();

	// Checks if the stack is empty
	bool is_empty();

	// Equality operator, checks if two stacks are equal
	bool operator==(const Stack& other);

	// Inequality operator, checks if two stacks are not equal
	bool operator!=(const Stack& other);

	// Greater than operator, checks if one stack is greater than another
	bool operator>(const Stack& other);

	// Less than operator, checks if one stack is less than another
	bool operator<(const Stack& other);

	// Adds an integer to every element of the stack
	Stack operator+=(const int number);

	// Subtracts an integer from every element of the stack
	Stack operator-=(const int number);

	// Multiplies every element of the stack by an integer
	Stack operator*=(const int number);

	// Divides every element of the stack by an integer
	Stack operator/=(const int number);

	// Adds two Stacks together and returns the result as a new Stack
	Stack operator+(Stack& other);

	// Adds another Stack to the current Stack and returns the modified current Stack
	Stack operator+=(Stack& other);
};