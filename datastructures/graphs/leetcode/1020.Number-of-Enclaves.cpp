class Solution
{
  int rows;
  int cols;

  void dfs(vector<vector<int>> &grid, int r, int c)
  {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
      return;

    if (grid[r][c] != 1)
      return;

    grid[r][c] = -1;

    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
  }

public:
  int numEnclaves(vector<vector<int>> &grid)
  {
    rows = grid.size();
    cols = grid[0].size();

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        if (r == 0 || c == 0 || r == rows - 1 || c == cols - 1)
        {
          dfs(grid, r, c);
        }
      }
    }

    int result = 0;
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        if (grid[r][c] == 1)
          ++result;
      }
    }

    return result;
  }
};