#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumPath(int rows, int cols, vector<vector<int>> &grid)
    {
        vector<int> prevRow(cols, 0);

        for (int i = 0; i < rows; i++)
        {
            vector<int> temp(cols, 0);

            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else
                {
                    int up = 0;
                    if (i > 0)
                        up = prevRow[j] + grid[i][j];
                    else
                        up += 1e9;

                    int left = 0;
                    if (j > 0)
                        left = temp[j - 1] + grid[i][j];
                    else
                        left += 1e9;

                    temp[j] = min(up, left);
                }
            }

            prevRow.swap(temp);
            temp.clear();
        }

        return prevRow[cols - 1];
    }
};

int main()
{
    vector<vector<int>> grid{
        {1, 1, 4},
        {3, 5, 2},
        {1, 1, 1}};

    int rows = grid.size();
    int cols = grid[0].size();

    Solution obj;

    cout << "Minimum sum path: "
         << obj.minSumPath(rows, cols, grid) << endl;
    return 0;
}