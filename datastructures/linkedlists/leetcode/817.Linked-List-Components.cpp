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
  int numComponents(ListNode *head, vector<int> &nums)
  {
    // count
    int count = 0;
    unordered_set<int> cache(begin(nums), end(nums));

    // ptr
    ListNode *currPtr = head;

    while (currPtr)
    {
      if (cache.count(currPtr->val) &&
          (!currPtr->next || cache.count(currPtr->next->val) == 0))
      {
        ++count;
      }
      currPtr = currPtr->next;
    }
    return count;
  }
};