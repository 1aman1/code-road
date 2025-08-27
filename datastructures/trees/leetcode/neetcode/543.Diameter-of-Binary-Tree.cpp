class Solution
{
    int height(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
            return 0;

        int leftSubtreeHeight = height(root->left, diameter);
        int rightSubtreeHeight = height(root->right, diameter);

        if (diameter < leftSubtreeHeight + rightSubtreeHeight)
            diameter = leftSubtreeHeight + rightSubtreeHeight;

        return 1 +
               max(leftSubtreeHeight, rightSubtreeHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};