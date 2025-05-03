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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0, head);
        unordered_map<int, ListNode *> sumToNode;
        int prefixSum = 0;

        ListNode *currNode = dummyHead;
        while (currNode)
        {
            prefixSum += currNode->val;
            sumToNode[prefixSum] = currNode;
            currNode = currNode->next;
        }

        prefixSum = 0;
        currNode = dummyHead;
        while (currNode)
        {
            prefixSum += currNode->val;
            currNode->next = sumToNode[prefixSum]->next;
            currNode = currNode->next;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};