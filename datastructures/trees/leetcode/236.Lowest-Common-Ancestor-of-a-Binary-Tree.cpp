/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr || root == p || root == q)
    {
      return root;
    }

    TreeNode *lst = lowestCommonAncestor(root->left, p, q);
    TreeNode *rst = lowestCommonAncestor(root->right, p, q);

    if (lst != nullptr && rst != nullptr)
    {
      return root;
    }

    return lst != nullptr ? lst : rst;
  }
};