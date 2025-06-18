class MyCircularQueue
{
  int front;
  int currentSize;
  int capacity;
  vector<int> q;

public:
  MyCircularQueue(int k) : capacity(k), currentSize(0), front(0)
  {
    q.resize(k);
  }

  bool enQueue(int value)
  {
    if (isFull())
      return false;

    int idx = (front + currentSize) % capacity;
    q[idx] = value;
    ++currentSize;
    return true;
  }

  bool deQueue()
  {
    if (isEmpty())
      return false;

    front = (front + 1) % capacity;
    --currentSize;
    return true;
  }

  int Front()
  {
    return isEmpty() ? -1 : q[front];
  }

  int Rear()
  {
    if (isEmpty())
      return -1;

    int idx = (front + currentSize - 1) % capacity;
    return q[idx];
  }

  bool isEmpty()
  {
    return currentSize == 0;
  }

  bool isFull()
  {
    return capacity == currentSize;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */