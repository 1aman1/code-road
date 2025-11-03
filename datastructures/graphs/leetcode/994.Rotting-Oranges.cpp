class Solution
{
  int digestGrid(const vector<vector<int>> &grid, const int &ROWS, const int &COLS, queue<pair<int, int>> &rottenOrangesQueue)
  {
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
          rottenOrangesQueue.emplace(r, c);
        }
      }
    }

    return countFresh;
  }

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    queue<pair<int, int>> rottenOrangesQueue;

    int countFresh = digestGrid(grid, ROWS, COLS, rottenOrangesQueue);

    if (not countFresh)
      return 0;

    vector<int> directions = {-1, 0, 1, 0, -1};
    int minutes = 0;

    while (not rottenOrangesQueue.empty() && countFresh > 0)
    {
      ++minutes;

      for (int i = rottenOrangesQueue.size(); i > 0; --i)
      {
        auto [row, col] = rottenOrangesQueue.front();
        rottenOrangesQueue.pop();

        for (int eachDirection = 0; eachDirection < 4; ++eachDirection)
        {
          int r = row + directions[eachDirection];
          int c = col + directions[eachDirection + 1];

          bool withinBounds = 0 <= r && r < ROWS && 0 <= c && c < COLS;

          if (withinBounds && grid[r][c] == 1)
          {
            grid[r][c] = 2;
            --countFresh;
            rottenOrangesQueue.emplace(r, c);
          }
        }
      }
    }

    return countFresh == 0 ? minutes : -1;
  }
};