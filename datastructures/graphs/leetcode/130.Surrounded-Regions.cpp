class Solution
{
  vector<pair<int, int>> indexes;
  int rows, cols;
  vector<vector<bool>> visited;

private:
  bool dfs(vector<vector<char>> &board, int r, int c)
  {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
      return false;

    if (board[r][c] != 'O' || visited[r][c])
      return true;

    visited[r][c] = true;
    indexes.push_back({r, c});

    bool isSurrounded = true;
    if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
      isSurrounded = false;

    bool up = dfs(board, r - 1, c);
    bool down = dfs(board, r + 1, c);
    bool left = dfs(board, r, c - 1);
    bool right = dfs(board, r, c + 1);

    return isSurrounded && up && down && left && right;
  }

public:
  void solve(vector<vector<char>> &board)
  {
    rows = board.size();
    cols = board[0].size();

    visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (board[i][j] == 'O')
        {
          indexes.clear();
          if (dfs(board, i, j))
          {
            for (const auto &pair : indexes)
            {
              board[pair.first][pair.second] = 'X';
            }
          }
        }
      }
    }
  }
};