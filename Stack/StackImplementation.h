#include <iostream>
#include <stdexcept>

template <typename T, size_t Capacity = 1000>
class Stack 
{
private:
    T array[Capacity];
    size_t top;

public:
    Stack();

    Stack(const Stack& other);

    Stack& operator=(const Stack& other);

    Stack(Stack&& other) noexcept;

    Stack& operator=(Stack&& other) noexcept;

    void swap(Stack& other) noexcept;

    void push(const T& item);

    T pop();

    bool isEmpty() const;

    size_t size() const;

    void printStack() const;
};