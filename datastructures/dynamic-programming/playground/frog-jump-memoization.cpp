#include <bits/stdc++.h>

using namespace std;

int solve(int idx, vector<int> &heights, vector<int> &cache)
{
    if (idx == 0)
        return 0;

    if (cache[idx] != -1)
        return cache[idx];

    int oneJump = abs(heights[idx] - heights[idx - 1]) + solve(idx - 1, heights, cache);

    int twoJumps = INT_MAX;
    if (idx >= 2)
    {
        twoJumps = abs(heights[idx] - heights[idx - 2]) + solve(idx - 2, heights, cache);
    }

    cache[idx] = min(oneJump, twoJumps);

    return cache[idx];
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int noOfSteps = heights.size();

    vector<int> cache(noOfSteps, -1);
    cout << solve(noOfSteps - 1, heights, cache);

    return 0;
}