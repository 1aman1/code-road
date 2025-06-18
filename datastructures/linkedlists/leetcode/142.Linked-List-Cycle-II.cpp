/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slowPtr, *fastPtr;

        slowPtr = fastPtr = head;

        while (fastPtr && fastPtr->next && fastPtr->next->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            // they will collide before pointing to null, if the list is circular
            if (slowPtr == fastPtr)
            {
                // start another single step pointer from head
                ListNode *PtrFromHead = head;

                while (slowPtr != PtrFromHead)
                {
                    slowPtr = slowPtr->next;
                    PtrFromHead = PtrFromHead->next;
                }

                return slowPtr;
            }
        }
        return nullptr;
    }
};