#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue()
    {
        if (s1.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int topVal = s1.top();
        s1.pop();
        return topVal;
    }

    bool isEmpty()
    {
        return s1.empty();
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
    cout << q.dequeue() << endl; // 30
    cout << q.dequeue() << endl; // Queue is empty
    return 0;
}
