#include <iostream>
#include <vector>
using namespace std;

int findParent(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x], parent); // Path compression
}

bool unionSets(int u, int v, vector<int> &parent)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if (pu == pv)
        return false; // Cycle found

    parent[pu] = pv; // Union
    return true;
}

bool hasCycle(int V, vector<pair<int, int>> &edges)
{
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (auto &edge : edges)
    {
        int u = edge.first, v = edge.second;
        if (!unionSets(u, v, parent))
            return true;
    }

    return false;
}

int main()
{
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {3, 4}};

    if (hasCycle(V, edges))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
