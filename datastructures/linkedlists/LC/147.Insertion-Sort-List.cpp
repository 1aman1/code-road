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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummyHead = new ListNode(INT_MIN, head);

        ListNode *prevNode = dummyHead;
        ListNode *currNode = head;

        while (currNode)
        {
            if (prevNode->val <= currNode->val)
            {
                prevNode = currNode;
                currNode = currNode->next;
                continue;
            }

            ListNode *posToInsertPtr = dummyHead;
            while (posToInsertPtr->next && posToInsertPtr->next->val <= currNode->val)
            {
                posToInsertPtr = posToInsertPtr->next;
            }

            ListNode *storeRestoftheList = currNode->next;
            currNode->next = posToInsertPtr->next;
            posToInsertPtr->next = currNode;

            prevNode->next = storeRestoftheList;

            currNode = storeRestoftheList;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};