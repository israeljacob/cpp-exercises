class Vector {
    int* arr;
    size_t my_size;
    size_t my_capacity;

public:
    Vector();  // Default constructor
    explicit Vector(size_t size, int value);  // Constructor with initial size and value
    Vector(const Vector& other);  // Copy constructor
    Vector(Vector&& other);  // Move constructor
    ~Vector();  // Destructor
    int& operator[](const int& index);  // Subscript operator
    Vector& operator=(Vector&& other);
    Vector& operator=(const Vector& other);  // Copy assignment operator
    const int& operator[](size_t index) const;  // Const subscript operator
    bool operator>(const Vector& other);  // Greater-than operator
    bool operator>=(const Vector& other);  // Greater-than-or-equal-to operator
    bool operator<(const Vector& other);  // Less-than operator
    bool operator<=(const Vector& other);  // Less-than-or-equal-to operator
    bool operator==(const Vector& other);  // Equality operator
    bool operator!=(const Vector& other);  // Inequality operator
    size_t size() const;  // Returns the current number of elements in the vector
    size_t capacity() const;  // Returns the current capacity of the vector
    bool empty() const;  // Returns true if the vector is empty, false otherwise
    int* data();  // Returns a pointer to the underlying array
    void clear();  // Removes all elements from the vector
    void swap(Vector& other);  // Swaps the contents of the current vector with `other`
    void resize(size_t newSize, int value);  // Resizes the vector
    void pop_back();  // Removes the last element from the vector
    void push_back(int value);  // Adds an element to the end of the vector

private:
    bool set_capacity(size_t size);  // Resizes the capacity of the array to at least `size`, if necessary
    void set_arr(size_t size);  // Allocates a new array of size `size` and sets `my_capacity` to `size`
};
