/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
    vector<TreeNode *> generateUniqueBSTs(int left, int right)
    {
        vector<TreeNode *> trees;

        if (left > right)
        {
            trees.push_back(nullptr);
        }
        else
        {
            for (int forEachRoot = left; forEachRoot <= right; ++forEachRoot)
            {
                vector<TreeNode *> LeftSubTrees = generateUniqueBSTs(left, forEachRoot - 1);
                vector<TreeNode *> RightSubTrees = generateUniqueBSTs(forEachRoot + 1, right);

                for (auto &pickEachLST : LeftSubTrees)
                {
                    for (auto &pickEachRST : RightSubTrees)
                    {
                        TreeNode *aTree = new TreeNode(forEachRoot, pickEachLST, pickEachRST);
                        trees.push_back(aTree);
                    }
                }
            }
        }
        return trees;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return generateUniqueBSTs(1, n);
    }
};