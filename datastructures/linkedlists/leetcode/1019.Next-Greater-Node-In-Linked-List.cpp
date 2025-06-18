/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> values;

        while (head != nullptr)
        {
            values.push_back(head->val);
            head = head->next;
        }

        int size = values.size();
        vector<int> result(size, 0);

        stack<int> stack;

        for (int i = size - 1; i >= 0; --i)
        {
            while (!stack.empty() && stack.top() <= values[i])
                stack.pop();

            if (!stack.empty())
                result[i] = stack.top();

            stack.push(values[i]);
        }

        return result;
    }
};