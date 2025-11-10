#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> minPathCache(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                    minPathCache[i][j] = grid[i][j];
                else
                {
                    int up = 0;
                    if (i > 0)
                        up = grid[i][j] + minPathCache[i - 1][j];
                    else
                        up = 1e9;

                    int left = 0;
                    if (j > 0)
                        left = grid[i][j] + minPathCache[i][j - 1];
                    else
                        left += 1e9;

                    minPathCache[i][j] = min(up, left);
                }
            }
        }

        return minPathCache[rows - 1][cols - 1];
    }
};

int main()
{
    vector<vector<int>> grid{
        {1, 1, 4},
        {3, 5, 2},
        {1, 1, 1}};

    Solution obj;
    cout << "Minimum sum path: " << obj.minPathSum(grid) << endl;
    return 0;
}