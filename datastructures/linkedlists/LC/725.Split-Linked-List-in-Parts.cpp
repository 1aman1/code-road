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
  vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    vector<ListNode *> result(k, nullptr);

    if (!head)
      return result;

    int length = 0;
    ListNode *currPtr = head;

    while (currPtr)
    {
      currPtr = currPtr->next;
      ++length;
    }

    int minLength = length / k;

    int extraNodes = length % k;

    currPtr = head;
    for (int i = 0; i < k; ++i)
    {
      ListNode *currHead = currPtr;
      int currSize = minLength + ((i < extraNodes) ? 1 : 0);

      for (int j = 0; j < currSize - 1 && currPtr; ++j)
      {
        currPtr = currPtr->next;
      }

      if (currPtr)
      {
        ListNode *holdNext = currPtr->next;
        currPtr->next = nullptr;
        currPtr = holdNext;
      }

      result[i] = currHead;
    }
    return result;
  }
};