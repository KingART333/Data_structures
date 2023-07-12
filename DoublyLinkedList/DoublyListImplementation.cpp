#include <iostream>
#include "DoublyListImlementation.h"

template<typename T>
List<T>::List()
    : size(0), head(nullptr), tail(nullptr)
{
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->pPrev = tail;
        tail->pNext = newNode;
        tail = newNode;
    }
    size++;
    
}

template<typename T>
void List<T>::push_front(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->pNext = head;
        head->pPrev = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void List<T>::pop_back()
{
    if (size == 0)
        return;

    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node *previous = tail->pPrev;
        previous->pNext = nullptr;
        delete tail;
        tail = previous;
    }
    size--;
}

template<typename T>
void List<T>::pop_front()
{
    if (size == 0)
        return;

    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node<T> *next = head->pNext;
        next->pPrev = nullptr;
        delete head;
        head = next;
    }
    size--;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index < 0 || index > size)
        return;

    if (index == 0)
    {
        push_front(data);
    }
    else if (index == size)
    {
        push_back(data);
    }
    else
    {
        Node<T> *previous = head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }
        Node<T> *newNode = new Node<T>(data);
        newNode->pNext = previous->pNext;
        newNode->pPrev = previous;
        previous->pNext = newNode;
        newNode->pNext->pPrev = newNode;
        size++;
    }
}

template<typename T>
void List<T>::clear()
{
    while (head != nullptr)
    {
        pop_front();
    }
    size = 0;
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        return;

    if (index == 0)
    {
        pop_front();
    }
    else if (index == size - 1)
    {
        pop_back();
    }
    else
    {
        Node *previous = head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }
        Node *current = previous->pNext;
        previous->pNext = current->pNext;
        current->pNext->pPrev = previous;
        delete current;
        size--;
    }
}

template<typename T>
int List<T>::getSize() const
{
    return size;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; ++i)
    {
        current = current->pNext;
    }

    return current->data;
}

template <typename T>
void List<T>::printList()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->pNext;
    }
    std::cout << std::endl;
}
