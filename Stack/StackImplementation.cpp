#include "StackImplementation.h"

template <typename T, size_t Capacity>
Stack<T, Capacity>::Stack()
    : top(0)
{
}

template <typename T, size_t Capacity>
Stack<T, Capacity>::Stack(const Stack& other)
    : top(other.top)
{
    std::copy(other.array, other.array + top, array);
}

template <typename T, size_t Capacity>
Stack<T, Capacity>& Stack<T, Capacity>::operator=(const Stack& other)
{
    if (this != &other)
    {
        top = other.top;
        std::copy(other.array, other.array + top, array);
    }
    return *this;
}

template <typename T, size_t Capacity>
Stack<T, Capacity>::Stack(Stack&& other) noexcept
    : top(other.top)
{
    std::copy(other.array, other.array + top, array);
    other.top = 0;
}

template <typename T, size_t Capacity>
Stack<T, Capacity>& Stack<T, Capacity>::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        top = other.top;
        std::copy(other.array, other.array + top, array);
        other.top = 0;
    }
    return *this;
}

template <typename T, size_t Capacity>
void Stack<T, Capacity>::swap(Stack& other) noexcept
{
    std::swap_ranges(array, array + top, other.array);
    std::swap(top, other.top);
}

template <typename T, size_t Capacity>
void Stack<T, Capacity>::push(const T& item)
{
    if (top >= Capacity)
    {
        throw std::overflow_error("Stack is full.");
    }
    array[top++] = item;
}

template <typename T, size_t Capacity>
T Stack<T, Capacity>::pop()
{
    if (top == 0)
    {
        throw std::runtime_error("Stack is empty.");
    }
    return array[--top];
}

template <typename T, size_t Capacity>
bool Stack<T, Capacity>::isEmpty() const
{
    return top == 0;
}

template <typename T, size_t Capacity>
size_t Stack<T, Capacity>::size() const
{
    return top;
}

template <typename T, size_t Capacity>
void Stack<T, Capacity>::printStack() const
{
    for (size_t i = 0; i < top; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}