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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

    vector<int> convertToArray(ListNode *head)
    {
        vector<int> values;
        ListNode *traverse = head;
        while (traverse != nullptr)
        {
            values.emplace_back(traverse->val);
            traverse = traverse->next;
        }

        return values;
    }

    TreeNode *buildBST(vector<int> &sortedValues, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = (right - left) / 2 + left;
        TreeNode *newNode = new TreeNode(sortedValues[mid]);

        newNode->left = buildBST(sortedValues, left, mid - 1);
        newNode->right = buildBST(sortedValues, mid + 1, right);

        return newNode;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> sortedValues = convertToArray(head);

        return buildBST(sortedValues, 0, sortedValues.size() - 1);
    }
};