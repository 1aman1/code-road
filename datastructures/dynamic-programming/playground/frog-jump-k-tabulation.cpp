#include <bits/stdc++.h>

using namespace std;

int solve(const int &noOfSteps, const vector<int> &heights, const int &k, vector<int> &cache)
{
    cache[0] = 0;

    for (int idx = 1; idx < noOfSteps; ++idx)
    {
        int minEnergy = INT_MAX;

        for (int j = 1; j <= k; ++j)
        {
            if (idx - j >= 0)
            {
                int jumpEnergy = abs(heights[idx] - heights[idx - j]) + cache[idx - j];
                minEnergy = min(minEnergy, jumpEnergy);
            }
        }
        cache[idx] = minEnergy;
    }

    return cache[noOfSteps - 1];
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};

    int noOfSteps = heights.size();
    int k = 2;
    vector<int> cache(noOfSteps, -1);
    cout << solve(noOfSteps, heights, k, cache) << endl;

    return 0;
}