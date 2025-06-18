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
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == nullptr ||
        head->next == nullptr)
      return head;

    int length = 1;
    ListNode *measuringTape = head;
    while (measuringTape->next != nullptr)
    {
      measuringTape = measuringTape->next;
      ++length;
    }

    // mod k with length
    k %= length;

    if (k == 0)
    {
      return head;
    }

    // add dummy ptr to head
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    // walk j nodes
    while (k--)
    {
      fastPtr = fastPtr->next;
    }
    while (fastPtr->next)
    {
      fastPtr = fastPtr->next;
      slowPtr = slowPtr->next;
    }

    ListNode *newHead = slowPtr->next;
    fastPtr->next = head;
    slowPtr->next = nullptr;

    return newHead;
  }
};