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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;

        ListNode *dummyHead = new ListNode(INT_MIN, head);
        ListNode *curr = dummyHead;
        ListNode *deleteNode = nullptr;

        while (curr && curr->next)
        {
            if (curr->next->val == val)
            {
                deleteNode = curr->next;
                curr->next = curr->next->next;
                delete deleteNode;
            }
            else
            {
                curr = curr->next;
            }
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};