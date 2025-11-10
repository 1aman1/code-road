#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, const vector<vector<int>> &triangle, const int SIZE, vector<vector<int>> &minSumCache)
    {
        if (minSumCache[i][j] != -1)
            return minSumCache[i][j];

        if (i == SIZE - 1)
            return triangle[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle, SIZE, minSumCache);
        int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, SIZE, minSumCache);

        return minSumCache[i][j] = min(down, diag);
    }

    int minimumPathSum(vector<vector<int>> &triangle)
    {
        const int SIZE = triangle.size();
        vector<vector<int>> minSumCache(SIZE, vector<int>(SIZE, -1));
        return solve(0, 0, triangle, SIZE, minSumCache);
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> triangle{
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}};
    cout << obj.minimumPathSum(triangle);
    return 0;
}