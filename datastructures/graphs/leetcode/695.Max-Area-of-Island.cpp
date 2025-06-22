class Solution
{
    int rows;
    int cols;
    vector<vector<bool>> visited;

    int dfs_explorer(vector<vector<int>> &grid, int r, int c)
    {
        bool rowCheck = 0 <= r && r < rows;
        bool colCheck = 0 <= c && c < cols;

        if (!rowCheck || !colCheck)
            return 0;

        if (grid[r][c] == 0 || visited[r][c])
            return 0;

        visited[r][c] = true;

        int size = 1;

        size += dfs_explorer(grid, r, c + 1);
        size += dfs_explorer(grid, r, c - 1);
        size += dfs_explorer(grid, r + 1, c);
        size += dfs_explorer(grid, r - 1, c);

        return size;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxIslandSize = 0;

        rows = grid.size();
        if (!rows)
            return maxIslandSize;

        cols = grid[0].size();

        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] && !visited[r][c])
                {
                    maxIslandSize = std::max(maxIslandSize, dfs_explorer(grid, r, c));
                }
            }
        }
        return maxIslandSize;
    }
};