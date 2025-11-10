#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &visited, stack<int> &nodeStack,
             vector<vector<int>> adj)
    {
        visited[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
                dfs(neighbour, visited, nodeStack, adj);
        }
        nodeStack.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> adj)
    {
        vector<int> visited(V, 0);
        stack<int> nodeStack;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, nodeStack, adj);
            }
        }

        vector<int> topologicalSequence;
        while (!nodeStack.empty())
        {
            topologicalSequence.push_back(nodeStack.top());
            nodeStack.pop();
        }
        return topologicalSequence;
    }
};

int main()
{
    vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    Solution obj;

    for (auto node : obj.topoSort(V, adj))
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}