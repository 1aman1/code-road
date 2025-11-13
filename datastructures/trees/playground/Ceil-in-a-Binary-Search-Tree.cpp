#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode
{
    // Value of the node
    int val;

    // Pointer to the left child node
    TreeNode *left;

    // Pointer to the right child node
    TreeNode *right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int findCeil(TreeNode *root, int key)
    {
        int ceil = -1;

        while (root)
        {
            if (root->val == key)
            {
                return key;
            }

            if (key < root->val)
            {
                ceil = root->val;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceil;
    }
};

void printInOrder(TreeNode *root)
{
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr)
    {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main()
{
    // Creating a BST
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution solution;

    // Searching for a value in the BST
    int target = 8;
    int ceil = solution.findCeil(root, target);

    if (ceil != -1)
    {
        cout << "Ceiling of " << target << " is: " << ceil << endl;
    }
    else
    {
        cout << "No ceiling found!";
    }

    return 0;
}