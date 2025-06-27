#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> v;

public:
    void push(int data)
    {
        v.push_back(data);
        cout << "Pushed: " << data << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
        int top = v.back();
        v.pop_back();
        return top;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        return v.back();
    }

    bool isEmpty() { return v.empty(); }
};

int main()
{
    Stack myStack;

    for (int i = 0; i <= 101; ++i)
    {
        myStack.push(i);
    }

    myStack.pop();

    int topElement = myStack.top();
    if (topElement != -1)
    {
        cout << "\nTop element: " << topElement << endl;
    }

    return 0;
}