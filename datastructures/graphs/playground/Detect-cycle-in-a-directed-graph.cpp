#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &onlyVisitedOnThisPath)
    {
        visited[node] = 1;
        onlyVisitedOnThisPath[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (dfs(neighbour, adj, visited, onlyVisitedOnThisPath))
                    return true;
            }
            else if (onlyVisitedOnThisPath[neighbour])
            {
                return true;
            }
        }

        onlyVisitedOnThisPath[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> onlyVisitedOnThisPath(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, onlyVisitedOnThisPath))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;
    Solution obj;
    bool ans = obj.isCyclic(V, adj);

    if (ans)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}