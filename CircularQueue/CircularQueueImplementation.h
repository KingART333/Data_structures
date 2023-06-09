 #include <iostream>

const int MAX_QUEUE = 1000;

template<typename T>
class Queue
{
public:
    Queue();
    bool isEmpty() const;
    void enqueue (T newItem);
    void dequeue();
    void dequeue(T& queueFront);
    T getFront() const;
    size_t size() const;

    

private:
    T items[MAX_QUEUE] {};
    size_t frontIndex;
    size_t backIndex;
    size_t count;
};

