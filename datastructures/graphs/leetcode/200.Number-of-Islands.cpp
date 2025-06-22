class Solution
{
    int rows;
    int cols;
    vector<vector<bool>> visited;

private:
    void dfs_explorer(vector<vector<char>> &grid, int r, int c)
    {
        bool rowCheck = 0 <= r && r < rows;
        bool colCheck = 0 <= c && c < cols;

        if (!rowCheck || !colCheck)
            return;

        if (grid[r][c] == '0' || visited[r][c])
            return;

        visited[r][c] = true;

        dfs_explorer(grid, r, c + 1);
        dfs_explorer(grid, r, c - 1);
        dfs_explorer(grid, r + 1, c);
        dfs_explorer(grid, r - 1, c);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int numIslands = 0;

        rows = grid.size();
        if (not rows)
            return numIslands;

        cols = grid[0].size();

        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == '1' && !visited[r][c])
                {
                    dfs_explorer(grid, r, c);
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }
};