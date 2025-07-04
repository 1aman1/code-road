class Solution
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    int ROWS = mat.size();
    int COLS = mat[0].size();

    vector<vector<int>> distance(ROWS, vector<int>(COLS, -1));
    queue<pair<int, int>> nodeQueue;

    for (int r = 0; r < ROWS; ++r)
    {
      for (int c = 0; c < COLS; ++c)
      {
        if (mat[r][c] == 0)
        {
          distance[r][c] = 0;
          nodeQueue.emplace(r, c);
        }
      }
    }

    vector<int> directions = {-1, 0, 1, 0, -1};
    while (!nodeQueue.empty())
    {
      auto [r, c] = nodeQueue.front();
      nodeQueue.pop();

      for (int i = 0; i < 4; ++i)
      {
        int row = r + directions[i];
        int col = c + directions[i + 1];

        bool withinBounds = 0 <= row && row < ROWS && 0 <= col && col < COLS;

        if (withinBounds && distance[row][col] == -1)
        {
          distance[row][col] = distance[r][c] + 1;
          nodeQueue.emplace(row, col);
        }
      }
    }
    return distance;
  }
};