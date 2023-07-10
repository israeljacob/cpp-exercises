#include "Vector.h"
#include <algorithm>
#include <stdexcept>

// Default constructor
Vector::Vector() : arr(nullptr), my_size(0), my_capacity(0) {}

// Constructor with initial size and value
Vector::Vector(size_t size, int value) : arr(new int[size]), my_size(size), my_capacity(size)
{
    std::fill_n(arr, size, value);
}

// Copy constructor
Vector::Vector(const Vector& other) : arr(new int[other.my_capacity]), my_size(other.my_size), my_capacity(other.my_capacity)
{
    std::copy(other.arr, other.arr + other.my_size, arr);
}

// Move constructor
Vector::Vector(Vector&& other) : arr(other.arr), my_size(other.my_size), my_capacity(other.my_capacity)
{
    other.arr = nullptr;
    other.my_size = 0;
    other.my_capacity = 0;
}

// Destructor
Vector::~Vector()
{
    delete[] arr;
}

// Subscript operator
int& Vector::operator[](const int& index)
{
    if (index < 0 || index >= my_size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

Vector& Vector::operator=(Vector&& other)
{
    if (this != &other) {
        delete[] arr; // Deallocate the current array
        arr = other.arr; // Move the pointer to the new array
        my_size = other.my_size; // Move the size information
        other.arr = nullptr; // Reset the other object's pointer
        other.my_size = 0; // Reset the other object's size
    }
    return *this;
}

// Copy assignment operator
Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        Vector temp(other);
        swap(temp);
    }
    return *this;
}

// Const subscript operator
const int& Vector::operator[](size_t index) const
{
    if (index >= my_size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

// Greater-than operator
bool Vector::operator>(const Vector& other)
{
    if (my_size > other.my_size) {
        return true;
    }
    else if (my_size < other.my_size) {
        return false;
    }
    else {
        for (size_t i = 0; i < my_size; i++) {
            if (arr[i] <= other.arr[i]) {
                return false;
            }
        }
        return true;
    }
}

// Greater-than-or-equal-to operator
bool Vector::operator>=(const Vector& other)
{
    return *this > other || *this == other;
}

// Less-than operator
bool Vector::operator<(const Vector& other)
{
    if (my_size < other.my_size) {
        return true;
    }
    else if (my_size > other.my_size) {
        return false;
    }
    else {
        for (size_t i = 0; i < my_size; i++) {
            if (arr[i] >= other.arr[i]) {
                return false;
            }
        }
        return true;
    }
}

// Less-than-or-equal-to operator
bool Vector::operator<=(const Vector& other)
{
    return *this < other || *this == other;
}

// Equality operator
bool Vector::operator==(const Vector& other)
{
    if (my_size != other.my_size) {
        return false;
    }
    for (size_t i = 0; i < my_size; i++) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
}

// Inequality operator
bool Vector::operator!=(const Vector& other)
{
    return !(*this == other);
}

// Returns the current number of elements in the vector
size_t Vector::size() const
{
    return my_size;
}

// Returns the current capacity of the vector
size_t Vector::capacity() const
{
    return my_capacity;
}

// Returns true if the vector is empty, false otherwise
bool Vector::empty() const
{
    return my_size == 0;
}

// Returns a pointer to the underlying array
int* Vector::data()
{
    return arr;
}

// Removes all elements from the vector
void Vector::clear()
{
    delete[] arr;
    arr = nullptr;
    my_size = 0;
    my_capacity = 0;
}

// Swaps the contents of the current vector with `other`
void Vector::swap(Vector& other)
{
    std::swap(arr, other.arr);
    std::swap(my_size, other.my_size);
    std::swap(my_capacity, other.my_capacity);
}

// Resizes the vector
void Vector::resize(size_t newSize, int value)
{
    if (newSize == my_size) {
        return;
    }
    if (newSize < my_size) {
        my_size = newSize;
        return;
    }
    if (newSize > my_capacity) {
        set_capacity(newSize);
    }
    for (size_t i = my_size; i < newSize; i++) {
        arr[i] = value;
    }
    my_size = newSize;
}

// Removes the last element from the vector
void Vector::pop_back()
{
    if (my_size > 0) {
        my_size--;
    }
}

// Adds an element to the end of the vector
void Vector::push_back(int value)
{
    if (my_size >= my_capacity) {
        set_capacity(my_size + 1);
    }
    arr[my_size] = value;
    my_size++;
}

// Resizes the capacity of the array to at least `size`, if necessary
bool Vector::set_capacity(size_t size)
{
    if (size <= my_capacity) {
        return false;
    }
    size_t new_capacity = std::max(my_capacity * 2, size);
    int* new_arr = new int[new_capacity];
    std::copy(arr, arr + my_size, new_arr);
    delete[] arr;
    arr = new_arr;
    my_capacity = new_capacity;
    return true;
}

// Allocates a new array of size size and sets my_capacity to size
void Vector::set_arr(size_t size)
{
    delete[] arr;
    arr = new int[size];
    my_size = 0;
    my_capacity = size;
}