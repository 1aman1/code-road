class UnionFind
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  UnionFind(int size)
  {
    parent.resize(size);
    rank.resize(size, 0);
    for (int i = 0; i < size; ++i)
      parent[i] = i;
  }

  int find(int x)
  {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  bool unionSets(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
      return false; // Already connected

    if (rank[rootX] < rank[rootY])
    {
      parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
      parent[rootY] = rootX;
    }
    else
    {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    
    return true;
  }
};

bool hasCycle(int n, vector<vector<int>> &edges)
{
  UnionFind uf(n);

  for (auto &edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    if (!uf.unionSets(u, v))
      return true; // cycle detected
  }

  return false;
}
