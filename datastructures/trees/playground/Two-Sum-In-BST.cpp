#include <iostream>
#include <vector>
#include <climits>
#include <stack>
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

// BSTIterator class for
// iterating through BST nodes
class BSTIterator
{
private:
    // Stack to store nodes
    stack<TreeNode *> myStack;
    // Flag to determine traversal direction
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool isReverse) : reverse(isReverse)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse)
        {
            pushAll(tmpNode->right);
        }
        else
        {
            pushAll(tmpNode->left);
        }
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            myStack.push(node);
            if (reverse)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};

// Solution class for performing
// operations on the BST
class Solution
{
public:
    // Function to find if there exists
    // a pair with a given sum in the BST
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = l.next();
            }
            else
            {
                j = r.next();
            }
        }
        return false;
    }
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
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
    // Sample binary search tree: 7 3 15 -1 -1 9 20
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Tree Initialized: ";
    printInOrder(root);
    cout << endl;

    Solution solution;
    int target = 22;
    bool exists = solution.findTarget(root, target);
    if (exists)
    {
        cout << "Pair with sum " << target << " exists." << endl;
    }
    else
    {
        cout << "Pair with sum " << target << " does not exist." << endl;
    }

    return 0;
}
