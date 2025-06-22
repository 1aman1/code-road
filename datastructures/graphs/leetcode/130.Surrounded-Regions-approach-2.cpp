class Solution
{
  int rows;
  int cols;

public:
  void solve(vector<vector<char>> &board)
  {
    rows = board.size();
    cols = board[0].size();

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        bool isBoundary = i == 0 || i == rows - 1 || j == 0 || j == cols - 1;
        if (isBoundary && board[i][j] == 'O')
        {
          dfs(board, i, j);
        }
      }
    }

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (board[i][j] == '$')
        {
          board[i][j] = 'O';
        }
        else if (board[i][j] == 'O')
        {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(vector<vector<char>> &board, int i, int j)
  {
    board[i][j] = '$';

    vector<int> dirs = {-1, 0, 1, 0, -1};

    for (int k = 0; k < 4; ++k)
    {
      int r = i + dirs[k];
      int c = j + dirs[k + 1];

      bool inBounds = (0 <= r && r < rows && 0 <= c && c < cols);
      if (inBounds && board[r][c] == 'O')
      {
        dfs(board, r, c);
      }
    }
  }
};