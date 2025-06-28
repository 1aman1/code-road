#include <iostream>

class LinkedList
{
private:
  struct Node
  {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  int count;

public:
  LinkedList() : head(nullptr), tail(nullptr), count(0) {}

  ~LinkedList()
  {
    while (head)
    {
      pop_front();
    }
  }

  void push_front(int value)
  {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr)
    {
      tail = newNode;
    }

    ++count;
  }

  void push_back(int value)
  {
    Node *newNode = new Node(value);
    if (tail)
    {
      tail->next = newNode;
      tail = newNode;
    }
    else
    {
      head = tail = newNode;
    }

    ++count;
  }

  void pop_front()
  {
    if (!head)
      return;

    Node *temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr)
    {
      tail = nullptr;
    }

    --count;
  }

  void print() const
  {
    Node *current = head;
    while (current)
    {
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "nullptr\n";
  }

  int size() const
  {
    return count;
  }

  bool empty() const
  {
    return head == nullptr;
  }
};

int main()
{

  LinkedList list;

  list.push_front(4);
  list.push_front(14);
  list.push_front(140);

  list.print();
  list.pop_front();

  list.print();
  return 0;
}