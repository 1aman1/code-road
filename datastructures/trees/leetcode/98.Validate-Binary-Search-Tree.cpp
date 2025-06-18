class Solution
{
  bool helperBST(long MIN, TreeNode *root, long MAX)
  {
    if (root)
    {
      if (MIN < root->val && root->val < MAX)
      {
        return helperBST(MIN, root->left, root->val) &&
               helperBST(root->val, root->right, MAX);
      }
      return false;
    }
    return true;
  }

public:
  bool isValidBST(TreeNode *root)
  {
    return helperBST(LONG_MIN, root, LONG_MAX);
  }
};