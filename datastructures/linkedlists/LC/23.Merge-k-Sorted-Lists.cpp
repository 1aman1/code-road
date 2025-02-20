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
  struct compare
  {
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
      return lhs->val > rhs->val;
    }
  };

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
    for (ListNode *eachList : lists)
    {
      if (eachList)
        minHeap.push(eachList);
    }

    while (!minHeap.empty())
    {
      ListNode *newNode = minHeap.top();
      minHeap.pop();
      
      if (newNode->next)
      {
        minHeap.push(newNode->next);
      }

      curr->next = newNode;
      curr = curr->next;
    }

    return head->next;
  }
};