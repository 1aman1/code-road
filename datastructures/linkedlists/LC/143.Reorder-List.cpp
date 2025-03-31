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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // find middle

        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        while (fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // split the lists
        ListNode *curr = slowPtr->next;
        slowPtr->next = nullptr;

        // reverse the second
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *first = head;
        ListNode *second = prev;

        // merge first->second->first->second
        while (second)
        {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};