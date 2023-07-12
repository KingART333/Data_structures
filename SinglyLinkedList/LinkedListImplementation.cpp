#include "LinkedListImplementation.h"

template<typename T>
class List<T>::Node
{
public:
    Node *pNext;
    T data;

    Node(T data = T(), Node *pNext = nullptr)
        : data(data), pNext(pNext) {}
};

template<typename T>
List<T>::List()
    : size(0), head(nullptr)
{
}

template<typename T>
List<T>::List(const List& list)
    : size(0), head(nullptr)
{
    Node *p = list.head;
    while (p != nullptr)
    {
        push_back(p->data);
        p = p->pNext;
    }
}

template<typename T>
List<T>::List(std::initializer_list<T> values)
    : size(0), head(nullptr)
{
    for (const T& value : values)
    {
        push_back(value);
    }
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
        head = new Node(data);
    }
    else
    {
        Node *current = head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node(data, head);
    size++;
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(size-1);
}

template<typename T>
void List<T>::pop_front()
{
    Node *temp = head;
    head = head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index < 0 || index > size-1)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node *previous = head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }
        Node *newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        size++;
    }
}

template<typename T>
void List<T>::clear()
{
    while (size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node *previous = head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }
        Node *temp = previous->pNext;
        previous->pNext = temp->pNext;
        delete temp;
        size--;
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    int counter = 0;
    Node *current = head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    // This line is unreachable, but added to avoid compiler warnings
    throw std::out_of_range("Index out of range");
}

template<typename T>
void List<T>::insertionSort()
{
    if (size <= 1)
    {
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr)
    {
        Node* next = current->pNext;
        Node* prevSorted = nullptr;
        Node* temp = sorted;

        while (temp != nullptr)
        {
            if (current->data > temp->data)
            {
                prevSorted = temp;
                temp = temp->pNext;
            }
            else
            {
                break;
            }
        }

        if (prevSorted == nullptr)
        {
            current->pNext = sorted;
            sorted = current;
        }
        else
        {
            prevSorted->pNext = current;
            current->pNext = temp;
        }

        current = next;
    }

    head = sorted;
}

template<typename T>
void List<T>::printList()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->pNext;
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::saveToFile(const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        Node* current = head;
        while (current != nullptr)
        {
            file << current->data << " ";
            current = current->pNext;
        }
        file.close();
        std::cout << "List saved to file: " << filename << std::endl;
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

template<typename T>
List<T> List<T>::readFromFile(const std::string& filename)
{
    List<T> newList;
    std::ifstream file(filename);
    if (file.is_open())
    {
        T value;
        while (file >> value)
        {
            newList.push_back(value);
        }
        file.close();
        std::cout << "List read from file: " << filename << std::endl;
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
    return newList;
}