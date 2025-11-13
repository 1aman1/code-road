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
    // Function to find the floor of a key
    // in a Binary Search Tree (BST)
    int floorInBST(TreeNode *root, int key)
    {
        // Initialize the floor variable
        int floor = -1;

        // Traverse the BST until root becomes null
        while (root)
        {
            // If key is equal to current node value
            // then it is the floor
            if (root->val == key)
            {
                return key;
            }

            if (root->val < key)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
    }
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode *root)
{
    // Base case: if node is null
    if (root == nullptr)
        return;

    // Left subtree
    printInOrder(root->left);

    // Print current node
    cout << root->val << " ";

    // Right subtree
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

    cout << "Binary Search Tree (Inorder): " << endl;
    printInOrder(root);
    cout << endl;

    Solution solution;

    // Key to find floor
    int target = 8;
    int floorVal = solution.floorInBST(root, target);

    if (floorVal != -1)
    {
        cout << "Floor of " << target << " is: " << floorVal << endl;
    }
    else
    {
        cout << "No floor found!" << endl;
    }

    return 0;
}