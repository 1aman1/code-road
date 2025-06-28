#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Heap
{
private:
    vector<int> elements;
    size_t noOfElements{0};

public:
    void buildHeap();
    void heapSort();
    bool isHeap();

    void push(int);
    int pop();
    int top();

    int size();
    void print();

private:
    void heapify(int, int);
    void bubbleUpNewElement();
};

void Heap::heapify(int index, int heapLen)
{
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;

    int max = index;
    if (leftChild < heapLen && elements[max] < elements[leftChild])
    {
        max = leftChild;
    }
    if (rightChild < heapLen && elements[max] < elements[rightChild])
    {
        max = rightChild;
    }

    if (max != index)
    {
        std::swap(elements[max], elements[index]);
        heapify(max, heapLen);
    }
}

void Heap::buildHeap()
{
    for (int i = noOfElements / 2 - 1; i >= 0; --i)
    {
        heapify(i, noOfElements);
    }
}

void Heap::heapSort()
{
    buildHeap();

    for (int i = noOfElements - 1; i > 0; --i)
    {
        std::swap(elements[0], elements[i]);
        heapify(0, i);
    }
}

bool Heap::isHeap()
{
    for (int i = 0; i <= noOfElements / 2 - 1; ++i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < noOfElements && elements[i] < elements[left] ||
            right < noOfElements && elements[i] < elements[right])
        {
            return false;
        }
    }
    return true;
}

int Heap::pop()
{
    if (elements.empty())
        return -1;

    int result = elements.front();
    std::swap(elements.front(), elements.back());
    elements.pop_back();
    --noOfElements;

    heapify(0, noOfElements);
    return result;
}

int Heap::top()
{
    if (elements.empty())
        return -1;

    return elements.front();
}

void Heap::bubbleUpNewElement()
{
    int i = noOfElements - 1;
    while (i > 0)
    {
        int parent = i - 1 / 2;
        if (elements[parent] < elements[i])
        {
            swap(elements[parent], elements[i]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void Heap::push(int newValue)
{
    elements.push_back(newValue);
    ++noOfElements;

    bubbleUpNewElement();
}

int Heap::size()
{
    return elements.size();
}

void Heap::print()
{
    for (const auto &e : elements)
    {
        cout << e << " ";
    }
    cout << "\n";
}

int main()
{
    Heap obj;

    obj.push(2);
    obj.push(20);
    obj.push(21);
    obj.push(4);
    obj.push(40);
    cout << obj.top() << "\n";

    cout << obj.pop() << "\n";
    cout << obj.top() << "\n";

    cout << std::boolalpha << obj.isHeap() << "\n";

    obj.heapSort();
    obj.print();
    cout << obj.top() << "\n";
    cout << std::boolalpha << obj.isHeap() << "\n";

    return 0;
}