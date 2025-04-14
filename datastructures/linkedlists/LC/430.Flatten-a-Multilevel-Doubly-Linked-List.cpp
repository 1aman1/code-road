class Solution
{
public:
    Node *flatten(Node *head)
    {
        flattenList(head);
        return head;
    }

private:
    Node *flattenList(Node *node)
    {
        Node *curr = node;
        Node *last = nullptr;

        while (curr)
        {
            Node *currNextNode = curr->next;

            if (curr->child)
            {
                Node *childHead = curr->child;
                Node *childTail = flattenList(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if (currNextNode)
                {
                    childTail->next = currNextNode;
                    currNextNode->prev = childTail;
                }

                last = childTail;
                curr = currNextNode;
            }
            else
            {
                last = curr;
                curr = curr->next;
            }
        }

        return last;
    }
};
