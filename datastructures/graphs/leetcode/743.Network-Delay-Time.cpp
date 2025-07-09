class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<pair<int, int>>> adjList(n + 1);
    int src = k;

    for (const auto &e : times)
    {
      int src = e[0];
      int dest = e[1];
      int weight = e[2];

      adjList[src].push_back({dest, weight});
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.emplace(0, src);

    while (not heap.empty())
    {
      auto [currDist, currNode] = heap.top();
      heap.pop();

      if (currDist > dist[currNode])
        continue;

      for (const auto &[neighbour, weight] : adjList[currNode])
      {
        if (dist[neighbour] > dist[currNode] + weight)
        {
          dist[neighbour] = dist[currNode] + weight;
          heap.emplace(dist[neighbour], neighbour);
        }
      }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; ++i)
    {
      if (dist[i] == INT_MAX)
        return -1;
      maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
  }
};