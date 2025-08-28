class Solution
{
public:
    void rotate(vector<vector<int>> &grid)
    {
        reverse(grid.begin(), grid.end());

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = i + 1; j < grid.size(); j++)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }
};