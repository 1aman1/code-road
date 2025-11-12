#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;

    map<int, vector<int>> nodes; // dist -> list of nodes
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto [node, dist] = q.front();
        q.pop();

        nodes[dist].push_back(node->val);

        if (node->left)
            q.push({node->left, dist - 1});
        if (node->right)
            q.push({node->right, dist + 1});
    }

    for (auto &it : nodes)
        result.push_back(it.second);

    return result;
}
