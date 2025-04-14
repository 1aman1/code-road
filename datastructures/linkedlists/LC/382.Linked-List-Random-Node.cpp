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
    ListNode *head = nullptr;

public:
    Solution(ListNode *head) : head(head)
    {
    }

    int getRandom()
    {
        int randomNumber = head->val;
        ListNode *curr = head->next;
        int nodesEncountered = 2;

        while (curr)
        {
            if (rand() % nodesEncountered == 0)
            {
                randomNumber = curr->val;
            }
            curr = curr->next;
            ++nodesEncountered;
        }

        return randomNumber;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */