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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        ListNode *dummyHead = new ListNode(0, head);

        ListNode *lhs = dummyHead;
        for (int i = 1; i < left; ++i)
            lhs = lhs->next;

        ListNode *curr = lhs->next;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        for (int i = 0; i <= right - left; ++i)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        lhs->next->next = curr;
        lhs->next = prev;

        ListNode *reversedList = dummyHead->next;
        delete dummyHead;
        return reversedList;
    }
};