#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int m, int n, vector<vector<int>> &numberOfWaysCache)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                numberOfWaysCache[0][0] = 1;
                continue;
            }

            int up = 0, left = 0;

            if (i > 0)
                up = numberOfWaysCache[i - 1][j];

            if (j > 0)
                left = numberOfWaysCache[i][j - 1];

            numberOfWaysCache[i][j] = up + left;
        }
    }

    return numberOfWaysCache[m - 1][n - 1];
}

int countWays(int m, int n)
{
    vector<vector<int>> numberOfWaysCache(m, vector<int>(n, -1));

    return countWaysUtil(m, n, numberOfWaysCache);
}

int main()
{
    int m = 11;
    int n = 6;

    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}