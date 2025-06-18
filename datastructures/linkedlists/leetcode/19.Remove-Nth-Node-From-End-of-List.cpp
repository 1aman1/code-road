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
  ListNode *removeNthFromEnd(ListNode *head, int k)
  {
    if (head == nullptr)
      return nullptr;

    ListNode *dummy = new ListNode(0, head);
    
    ListNode *slowPtr = dummy;
    ListNode *fastPtr = dummy;

    while (k > 0)
    {
      fastPtr = fastPtr->next;
      k--;
    }

    while (fastPtr->next != nullptr)
    {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
    }

    ListNode *nodeToRemove = slowPtr->next;
    slowPtr->next = nodeToRemove->next;
    delete nodeToRemove;

    ListNode *newHead = dummy->next;
    delete dummy;

    return newHead;
  }
};