#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *inOrderStart;
    TreeNode *inOrderEnd;
    TreeNode(int x) : val(x), inOrderStart(nullptr), inOrderEnd(nullptr) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorderSeq)
    {
        if (inorder.size() != postorderSeq.size())
        {
            return NULL;
        }

        map<int, int> lookupCache;
        for (int i = 0; i < inorder.size(); i++)
        {
            lookupCache[inorder[i]] = i;
        }

        return buildTreePostIn(0, inorder.size() - 1,
                               postorderSeq, 0, postorderSeq.size() - 1,
                               lookupCache);
    }

    TreeNode *buildTreePostIn(int inOrderStart, int inOrderEnd,
                              vector<int> &postorderSeq, int postOrderStart, int postOrderEnd,
                              map<int, int> &lookupCache)
    {
        if (postOrderStart > postOrderEnd || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorderSeq[postOrderEnd]);
        int inRoot = lookupCache[postorderSeq[postOrderEnd]];
        int numsLeft = inRoot - inOrderStart;

        root->inOrderStart = buildTreePostIn(inOrderStart, inRoot - 1,
                                             postorderSeq, postOrderStart, postOrderStart + numsLeft - 1,
                                             lookupCache);

        root->inOrderEnd = buildTreePostIn(inRoot + 1, inOrderEnd,
                                           postorderSeq, postOrderStart + numsLeft, postOrderEnd - 1,
                                           lookupCache);

        return root;
    }
};

// Function to print the
// inorder traversal of a tree
void printInorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    printInorder(root->inOrderStart);
    cout << root->val << " ";
    printInorder(root->inOrderEnd);
}

// Function to print the given vector
void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorderSeq = {40, 50, 20, 60, 30, 10};

    cout << "Inorder Vector: ";
    printVector(inorder);

    cout << "Postorder Vector: ";
    printVector(postorderSeq);

    Solution sol;

    TreeNode *root = sol.buildTree(inorder, postorderSeq);

    cout << "Inorder of Unique Binary Tree Created: " << endl;
    printInorder(root);
    cout << endl;

    return 0;
}
