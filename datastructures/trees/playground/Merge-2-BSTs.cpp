#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Push all left nodes of a tree into the stack
void pushLeft(TreeNode *node, stack<TreeNode *> &st)
{
    while (node)
    {
        st.push(node);
        node = node->left;
    }
}

// Merge two BSTs into sorted order
void mergeBSTs(TreeNode *root1, TreeNode *root2)
{
    stack<TreeNode *> s1, s2;
    pushLeft(root1, s1);
    pushLeft(root2, s2);

    while (!s1.empty() || !s2.empty())
    {
        stack<TreeNode *> &s =
            s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)
                ? s1
                : s2;

        TreeNode *node = s.top();
        s.pop();

        cout << node->val << " ";

        pushLeft(node->right, s);
    }
}

int main()
{
    // Example 1:
    // Tree 1:     2
    //            / \
    //           1   4
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    // Tree 2:     3
    //            / \
    //           0   5
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(5);

    cout << "Merged elements: ";
    mergeBSTs(root1, root2);
    cout << endl;
}
