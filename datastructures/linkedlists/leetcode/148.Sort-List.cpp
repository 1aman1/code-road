/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *slowPtr = head;
        ListNode *fastPtr = head->next;
        while (fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode *rightHead = slowPtr->next;
        slowPtr->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(rightHead);

        ListNode *dummyHead = new ListNode();
        ListNode *curr = dummyHead;

        while (left && right)
        {
            if (left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        curr->next = left ? left : right;

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};