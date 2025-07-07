class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    queue<pair<int, int>> nodeQueue;

    int countFresh = 0;
    for (int r = 0; r < ROWS; ++r)
    {
      for (int c = 0; c < COLS; ++c)
      {
        if (grid[r][c] == 1)
        {
          ++countFresh;
        }
        else if (grid[r][c] == 2)
        {
          nodeQueue.emplace(r, c);
        }
      }
    }
    if (not countFresh)
      return 0;

    vector<int> directions = {-1, 0, 1, 0, -1};
    int minutes = 0;

    while (not nodeQueue.empty() && countFresh > 0)
    {
      ++minutes;

      for (int i = nodeQueue.size(); i > 0; --i)
      {
        auto [row, col] = nodeQueue.front();
        nodeQueue.pop();

        for (int eachDirection = 0; eachDirection < 4; ++eachDirection)
        {
          int r = row + directions[eachDirection];
          int c = col + directions[eachDirection + 1];

          bool withinBounds = 0 <= r && r < ROWS && 0 <= c && c < COLS;

          if (withinBounds && grid[r][c] == 1)
          {
            grid[r][c] = 2;
            --countFresh;
            nodeQueue.emplace(r, c);
          }
        }
      }
    }

    return countFresh == 0 ? minutes : -1;
  }
};