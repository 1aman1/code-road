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
  pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail)
  {
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != tail)
    {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }

    return {tail, head};
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (!head)
      return nullptr;

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *predecessor = dummyHead;

    while (head)
    {
      ListNode *tail = predecessor;

      for (int i = 0; i < k; ++i)
      {
        tail = tail->next;
        if (tail == nullptr)
          return dummyHead->next;
      }
      ListNode *successor = tail->next;

      auto reversedList = reverse(head, tail);

      // place the reversed list in same place
      predecessor->next = reversedList.first;
      reversedList.second->next = successor;

      predecessor = reversedList.second;
      head = successor;
    }

    return dummyHead->next;
  }
};