class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        while (root)
        {
            if (root->left)
            {
                TreeNode *currNode = root->left;
                while (currNode->right)
                {
                    currNode = currNode->right;
                }
                currNode->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};