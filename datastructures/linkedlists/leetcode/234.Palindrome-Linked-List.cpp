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
    pair<ListNode *, ListNode *> partitionList(ListNode *head)
    {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head->next;

        while (fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode *rhslistHead = slowPtr->next;
        slowPtr->next = nullptr;

        return {head, rhslistHead};
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nextPtr = nullptr;

        while (curr)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        return prev;
    }

    bool compare(ListNode *lhsHalf, ListNode *rhsHalf)
    {
        while (lhsHalf && rhsHalf)
        {
            if (lhsHalf->val != rhsHalf->val)
            {
                return false;
            }
            lhsHalf = lhsHalf->next;
            rhsHalf = rhsHalf->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true;
        }

        auto [lhsHead, rhsHead] = partitionList(head);

        rhsHead = reverse(rhsHead);

        return compare(lhsHead, rhsHead);
    }
};