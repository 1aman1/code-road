#include <bits/stdc++.h>
using namespace std;

// Define a class to hold the solution
class Solution
{
public:
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {
        vector<int> front(n, 0);
        vector<int> cur(n, 0);

        for (int j = 0; j < n; j++)
        {
            front[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                cur[j] = triangle[i][j] + min(front[j], front[j + 1]);
            }

            front = cur;
        }

        return cur[0];
    }
};

int main()
{
    vector<vector<int>> triangle{
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}};

    int n = triangle.size();

    Solution obj;

    cout << obj.minimumPathSum(triangle, n);

    return 0;
}