#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPath(int i, int j,
                vector<vector<int>> &minPathCache,
                vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return 1e9;

        if (minPathCache[i][j] != -1)
            return minPathCache[i][j];

        int up = grid[i][j] +
                 minPath(i - 1, j, minPathCache, grid);

        int left = grid[i][j] +
                   minPath(i, j - 1, minPathCache, grid);

        return minPathCache[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> minPathCache(rows, vector<int>(cols, -1));

        return minPath(rows - 1, cols - 1, minPathCache, grid);
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 4},
        {3, 5, 2},
        {1, 1, 1}};

    Solution obj;
    cout << "Minimum sum path: "
         << obj.minPathSum(grid) << endl;

    return 0;
}