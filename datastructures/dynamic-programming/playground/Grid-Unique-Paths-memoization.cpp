#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int i, int j, vector<vector<int>> &numberOfWaysCache)
{
    if (i < 0 || j < 0)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (numberOfWaysCache[i][j] != -1)
        return numberOfWaysCache[i][j];

    int up = countWaysUtil(i - 1, j, numberOfWaysCache);
    int left = countWaysUtil(i, j - 1, numberOfWaysCache);

    return numberOfWaysCache[i][j] = up + left;
}

int countWays(int m, int n)
{
    vector<vector<int>> numberOfWaysCache(m, vector<int>(n, -1));

    return countWaysUtil(m - 1, n - 1, numberOfWaysCache);
}

int main()
{
    int m = 11;
    int n = 6;

    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}