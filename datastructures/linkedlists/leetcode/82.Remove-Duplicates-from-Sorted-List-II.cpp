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
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (!head)
      return nullptr;

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *curr = head;
    ListNode *prev = dummyHead;

    while (curr)
    {
      while (curr->next && curr->val == curr->next->val)
        curr = curr->next;

      if (prev->next == curr)
      {
        prev = curr;
      }
      else
      {
        prev->next = curr->next;
      }

      curr = curr->next;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};