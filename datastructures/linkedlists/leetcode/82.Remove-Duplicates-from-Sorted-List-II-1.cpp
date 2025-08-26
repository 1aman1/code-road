class Solution
{
  void nodeShredder(ListNode *duplicateRange, ListNode *head)
  {
    while (duplicateRange->next != head->next)
    {
      ListNode *deleteCandidate = duplicateRange;
      duplicateRange = duplicateRange->next;
      delete deleteCandidate;
    }
  }

public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *prev = dummyHead;

    while (head != nullptr)
    {
      while (head->next && head->val == head->next->val)
        head = head->next;

      if (prev->next == head)
      {
        prev = prev->next;
      }
      else
      {
        ListNode *duplicateRange = prev->next;
        nodeShredder(duplicateRange, head);
        prev->next = head->next;
      }

      head = head->next;
    }

    head = dummyHead->next;
    delete dummyHead;

    return head;
  }
};