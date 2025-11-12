#include <iostream>
#include <algorithm>
#include <math.h>

struct node
{
    int datum;
    node *left;
    node *right;

    node(int newdata) : datum(newdata),
                        left(nullptr),
                        right(nullptr) {}
};

int checkHeight(node *root)
{
    if (!root)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced_2nd(node *root)
{
    return (checkHeight(root) != -1);
}

int main()
{
    node *root = new node(1);
    root->left = new node(1);

    root->right = new node(1);
    // root->left->right = new node(1);

    // std::cout << "Is tree balanced ? " << std::boolalpha << isBalanced(root) << std::endl;
    std::cout << "Is tree balanced ? " << std::boolalpha << isBalanced_2nd(root) << std::endl;

    return 0;
}