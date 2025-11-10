#include <bits/stdc++.h>
using namespace std;

int countWays(int m, int n)
{
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);

        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }

            int up = 0, left = 0;

            if (i > 0)
                up = prev[j];

            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }

        prev.swap(temp);
        temp.clear();
    }

    return prev[n - 1];
}

int main()
{
    int m = 11;
    int n = 6;

    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}