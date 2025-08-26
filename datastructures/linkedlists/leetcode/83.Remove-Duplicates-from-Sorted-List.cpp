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

// @->1
// @->1->1
// @->1->1->1
// @->1->1->2->3

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *curr = dummyHead;
    ListNode *delCandidate = nullptr;

    while (curr != nullptr && curr->next != nullptr && curr->next->next != nullptr)
    {
      if (curr->next->val == curr->next->next->val)
      {
        delCandidate = curr->next;
        curr->next = curr->next->next;
        delete delCandidate;
      }
      else
      {
        curr = curr->next;
      }
    }

    return dummyHead->next;
  }
};