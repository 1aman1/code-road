class Solution
{
public:
    void rotate(vector<vector<int>> &grid)
    {
        reverse(begin(grid), end(grid));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = i + 1; j < grid.size(); j++)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }
};