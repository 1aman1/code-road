class Solution
{
  vector<vector<int>> grid;

  int dfs(int thisEmp, const vector<int> &informTime)
  {
    int maxSubordinateTime = 0;

    for (const auto &sub : grid[thisEmp])
    {
      maxSubordinateTime = max(maxSubordinateTime, dfs(sub, informTime));
    }
    maxSubordinateTime += informTime[thisEmp];

    return maxSubordinateTime;
  }

public:
  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
  {
    grid.resize(n);

    for (int i = 0; i < n; ++i)
    {
      if (i != headID)
        grid[manager[i]].push_back(i);
    }

    return dfs(headID, informTime);
  }
};
