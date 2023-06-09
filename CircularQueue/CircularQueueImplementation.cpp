#include "CircularQueueImplementation.h"

template<typename T>
    Queue<T>::Queue() : frontIndex(0), backIndex(MAX_QUEUE-1), count(0)
    {
    }

template<typename T>
    bool Queue<T>::isEmpty() const
    {
        return bool(count == 0);
    }

template<typename T>
    void Queue<T>::enqueue(T newItem)
    {
        if (count == MAX_QUEUE)
            throw std::overflow_error("Queue is full");
        else
        {
            backIndex = (backIndex + 1) % MAX_QUEUE;
            items[backIndex] = newItem;
            ++count;
        }
    }

template<typename T>
    void Queue<T>::dequeue()
    {
        if (isEmpty())
            throw std::underflow_error("Queue is empty");
        else
        {
            frontIndex = (frontIndex + 1) % MAX_QUEUE;
            --count;
        }
    }

template<typename T>
    void Queue<T>::dequeue(T& queueFront)
    {
        if (isEmpty())
            throw std::underflow_error("Queue is empty");
        else
            queueFront = items[frontIndex];
    }

template<typename T>
    T Queue<T>::getFront() const
    {
        if (isEmpty())
            throw std::underflow_error("Queue is empty");
        else
            return items[frontIndex];
    }

template<typename T>
    size_t Queue<T>::size() const
    {
        return count;
    }
