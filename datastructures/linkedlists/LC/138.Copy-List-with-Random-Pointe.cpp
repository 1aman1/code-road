/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    void DeepCopyAndInterleave(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = curr->next->next;
        }
    }

    void reflectRandoms(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
    }

    Node *extractNewList(Node *head)
    {
        Node *curr = head;
        Node *newHead = head->next;
        Node *newCurr = newHead;

        while (curr)
        {
            curr->next = curr->next->next;
            if (newCurr->next)
                newCurr->next = newCurr->next->next;

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        DeepCopyAndInterleave(head);

        reflectRandoms(head);

        Node *newList = extractNewList(head);

        return newList;
    }
};