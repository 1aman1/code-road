class Solution
{
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *prevNode = list1;
    ListNode *nextNode = list1;

    for (int i = 1; i < a; ++i)
    {
      prevNode = prevNode->next;
    }

    for (int i = 0; i <= b; ++i)
    {
      nextNode = nextNode->next;
    }

    prevNode->next = list2;

    while (prevNode->next)
    {
      prevNode = prevNode->next;
    }

    prevNode->next = nextNode;

    return list1;
  }
};