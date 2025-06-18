struct Node
{
    int val;
    Node *next;

    Node(int x) : val(x), next(nullptr)
    {
    }
};

class MyLinkedList
{

    Node *head;
    int size;

public:
    MyLinkedList() : head(nullptr), size(0)
    {
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;

        Node *traverse = head;
        while (index--)
            traverse = traverse->next;

        return traverse->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        ++size;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *currNode = head;

            while (currNode->next)
            {
                currNode = currNode->next;
            }
            currNode->next = newNode;
        }

        ++size;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *prePtr = head;

        while (--index)
        {
            prePtr = prePtr->next;
        }

        newNode->next = prePtr->next;
        prePtr->next = newNode;

        ++size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        Node *currPtr;

        if (index == 0)
        {
            currPtr = head;
            head = head->next;
        }
        else
        {
            Node *prePtr = head;
            for (int i = 0; i < index - 1; ++i)
            {
                prePtr = prePtr->next;
            }

            currPtr = prePtr->next;
            prePtr->next = currPtr->next;
        }

        delete currPtr;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */