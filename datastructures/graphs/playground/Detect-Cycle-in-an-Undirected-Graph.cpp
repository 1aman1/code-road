#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detect(int src, vector<int> adj[], vector<int> visited)
    {
        visited[src] = 1;
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({src, -1});
        
        while (!bfsQueue.empty())
        {
            int node = bfsQueue.front().first;
            int parent = bfsQueue.front().second;
            bfsQueue.pop();

            for (auto adjacentNode : adj[node])
            {
                if (!visited[adjacentNode])
                {
                    visited[adjacentNode] = 1;
                    bfsQueue.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}