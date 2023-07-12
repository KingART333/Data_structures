template<typename T>
class Node
{
public:
    Node *pNext;
    Node *pPrev;
    T data;

    Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
        : data(data), pNext(pNext), pPrev(pPrev) {}
};

template<typename T>
class List
{
public:
    List();
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
    void printList();
    void sort();

private:
    int size;
    Node<T> *head;
    Node<T> *tail;
};