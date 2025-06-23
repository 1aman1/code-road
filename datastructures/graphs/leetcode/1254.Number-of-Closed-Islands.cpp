class Solution
{
  int rows;
  int cols;
  vector<vector<bool>> visited;

  void dfs(int r, int c, vector<vector<int>> &grid)
  {
    if (r < 0 || r >= rows || c < 0 || c >= cols ||
        grid[r][c] != 0 ||
        visited[r][c])
      return;

    visited[r][c] = true;

    dfs(r + 1, c, grid);
    dfs(r - 1, c, grid);
    dfs(r, c + 1, grid);
    dfs(r, c - 1, grid);
  }

public:
  int closedIsland(vector<vector<int>> &grid)
  {
    if (grid.empty())
      return 0;

    rows = grid.size();
    cols = grid[0].size();

    visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && grid[i][j] == 0 && !visited[i][j])
        {
          dfs(i, j, grid);
        }
      }
    }

    int totalComponents = 0;
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (grid[i][j] == 0 &&
            !visited[i][j])
        {
          dfs(i, j, grid);
          ++totalComponents;
        }
      }
    }

    return totalComponents;
  }
};