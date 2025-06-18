class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftHeight = 0, rightHeight = 0;

        while (left)
        {
            left = left->left;
            leftHeight++;
        }

        while (right)
        {
            right = right->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight)
            return (1 << (leftHeight + 1)) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
