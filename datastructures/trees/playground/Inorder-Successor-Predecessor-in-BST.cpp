#include <bits/stdc++.h>
using namespace std;

// define tree node structure
struct TreeNode
{
    // value of the node
    int val;
    // pointer to left child
    TreeNode *left;
    // pointer to right child
    TreeNode *right;
    // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution class
class Solution
{
public:
    // find inorder successor iteratively
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr;
        while (root != nullptr)
        {
            if (root->val >= p->val)
            {
                successor = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return successor;
    }
};

// inorder print helper
void printInOrder(TreeNode *root)
{
    // base case
    if (root == nullptr)
        return;
    // traverse left
    printInOrder(root->left);
    // print node
    cout << root->val << " ";
    // traverse right
    printInOrder(root->right);
}

// program entry
int main()
{
    // construct BST
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // show inorder
    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    // target node p
    TreeNode *p = root->left->right;

    // find successor
    Solution solution;
    TreeNode *successor = solution.inorderSuccessor(root, p);

    // print result
    if (successor != nullptr)
    {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    }
    else
    {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    // exit
    return 0;
}