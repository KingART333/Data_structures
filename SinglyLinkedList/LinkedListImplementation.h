#include <iostream>
#include <fstream>
#include <initializer_list>

template<typename T>
class List
{
public:
    List();
    List(const List& list);
    List(std::initializer_list<T> values);
    ~List();
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void insert(T data, int index);
    void clear();
    void removeAt(int index);
    int getSize() const;
    T& operator[](const int index);
    void insertionSort();
    void printList();
    void saveToFile(const std::string& filename);
    static List<T> readFromFile(const std::string& filename);

private:
    class Node;
    int size;
    Node *head;
};