#include <bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int> &heights, vector<int> &cache)
{
    if (ind == 0)
        return 0;

    if (cache[ind] != -1)
        return cache[ind];

    int tookOneJump = abs(heights[ind] - heights[ind - 1]) + solve(ind - 1, heights, cache);

    int tookTwoJumps = INT_MAX;
    if (ind > 1)
    {
        tookTwoJumps = abs(heights[ind] - heights[ind - 2]) + solve(ind - 2, heights, cache);
    }

    cache[ind] = min(tookOneJump, tookTwoJumps);

    return cache[ind];
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int noOfSteps = heights.size();

    vector<int> cache(noOfSteps, -1);
    cout << solve(noOfSteps - 1, heights, cache);
}