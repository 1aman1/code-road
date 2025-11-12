#include <bits/stdc++.h>
using namespace std;

// Definition of the binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // Function to calculate minimum time to burn the entire tree from the target node
    int minTime(TreeNode *root, int target)
    {
        // Create an undirected graph using adjacency list
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);

        unordered_set<int> visited;

        queue<int> q;
        q.push(target);
        visited.insert(target);

        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            time++;

            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node])
                {
                    if (!visited.count(neighbor))
                    {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return time - 1;
        }

private:
    void buildGraph(TreeNode *node, TreeNode *parent, unordered_map<int, vector<int>> &graph)
    {
        if (!node)
            return;

        if (parent)
        {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        // Recursively connect left and right children
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
};

// Driver code
int main()
{
    // Create the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    // Create solution object
    Solution sol;

    // Set target node to burn from
    int target = 1;

    // Print the minimum time to burn the tree
    cout << "Minimum time to burn the tree: " << sol.minTime(root, target) << endl;

    return 0;
}