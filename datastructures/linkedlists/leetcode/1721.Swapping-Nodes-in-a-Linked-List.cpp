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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        ListNode *leftNode = nullptr;
        ListNode *rightNode = nullptr;

        while (--k)
        {
            fastPtr = fastPtr->next;
        }

        leftNode = fastPtr;

        while (fastPtr->next != nullptr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        rightNode = slowPtr;

        swap(leftNode->val, rightNode->val);

        return head;
    }
};