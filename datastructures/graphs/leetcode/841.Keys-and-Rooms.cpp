class Solution
{
  void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int thisRoom)
  {
    visited[thisRoom] = true;

    for (const auto &eachKey : rooms[thisRoom])
    {
      if (!visited[eachKey])
      {
        dfs(rooms, visited, eachKey);
      }
    }
  }

public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    int rows = rooms.size();

    vector<bool> visited(rows, false);

    dfs(rooms, visited, 0);

    return std::all_of(visited.begin(), visited.end(), [](bool stillLocked)
                       { return stillLocked; });
  }
};