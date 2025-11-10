#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int currColor, vector<int> &color, vector<vector<int>> adj)
    {
        color[node] = currColor;

        for (auto neighbour : adj[node])
        {
            if (currColor == color[neighbour])
            {
                return false;
            }
            else if (color[neighbour] == -1)
            {
                if (!dfs(neighbour, !currColor, color, adj))
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>> adj)
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, 0, color, adj))
                    return false;
            }
        }
        return true;
    }
};

void addEdge(vector<vector<int>> adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<vector<int>> adj(4);

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    if (obj.isBipartite(4, adj))
        cout << "yes\n";
    else
        cout << "no\n";

    return 0;
}