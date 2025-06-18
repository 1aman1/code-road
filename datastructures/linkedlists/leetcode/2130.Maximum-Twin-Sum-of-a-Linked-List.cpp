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
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *firstHalf = head;
        ListNode *secondHalfStart = slow->next;

        ListNode *secondHalf = reverse(secondHalfStart);

        int maxPairSum = 0;

        while (firstHalf && secondHalf)
        {
            maxPairSum = max(maxPairSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxPairSum;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};