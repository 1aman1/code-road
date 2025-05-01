class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0, head);

        ListNode *slowPointer = dummyHead;
        ListNode *fastPointer = head;

        while (fastPointer && fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        ListNode *toDelete = slowPointer->next;
        slowPointer->next = slowPointer->next->next;

        delete toDelete;

        ListNode *newHead = dummyHead->next;
        delete dummyHead;

        return newHead;
    }
};