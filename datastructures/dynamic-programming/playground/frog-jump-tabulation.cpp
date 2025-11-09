#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &heights, vector<int> &cache)
{
    cache[0] = 0;
    const int SIZE = heights.size();

    for (int steps = 1; steps < SIZE; ++steps)
    {
        int jumpOne, jumpTwo;

        jumpOne = cache[steps - 1] + std::abs(heights[steps] - heights[steps - 1]);
        jumpTwo = INT_MAX;
        if (steps >= 2)
        {
            jumpTwo = cache[steps - 2] + std::abs(heights[steps] - heights[steps - 2]);
        }
        cache[steps] = min(jumpOne, jumpTwo);
    }

    return cache[SIZE - 1];
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int noOfSteps = heights.size();

    vector<int> cache(noOfSteps, -1);
    cout << solve(heights, cache) << endl;
}