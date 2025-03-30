class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root || !(root->left) && !(root->right))
            return;

        while (root)
        {
            if (root->left)
            {
                TreeNode *curr = root->left;
                while (curr->right)
                    curr = curr->right;

                curr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            root = root->right;
        }
    }
};