#include <iostream>

class Queue
{
private:
    int *data;
    int front;    // Index of the front element
    int offset;   // Number of elements in the queue
    int capacity; // Maximum size of the queue

public:
    Queue(int size)
    {
        capacity = size;
        data = new int[capacity];
        front = 0;
        offset = 0;
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cerr << "Queue overflow: Cannot enqueue, queue is full.\n";
            return;
        }

        int rearIndex = (front + offset) % capacity;
        data[rearIndex] = value;
        ++offset;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Queue underflow: Cannot dequeue, queue is empty.\n";
            return;
        }

        front = (front + 1) % capacity;
        --offset;
    }

    int peek() const
    {
        if (isEmpty())
        {
            std::cerr << "Queue is empty.\n";
            return -1;
        }
        return data[front];
    }

    bool isEmpty() const
    {
        return offset == 0;
    }

    bool isFull() const
    {
        return offset == capacity;
    }

    int size() const
    {
        return offset;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << "Front element: " << q.peek() << "\n";

    q.dequeue();
    q.enqueue(6);

    while (!q.isEmpty())
    {
        std::cout << q.peek() << " ";
        q.dequeue();
    }

    std::cout << "\n";
    return 0;
}
