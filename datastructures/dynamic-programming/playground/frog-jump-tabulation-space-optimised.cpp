#include <bits/stdc++.h>

using namespace std;

int solve(int noOfSteps, vector<int> &heights)
{
    int currentIdx = 0;
    int idx_minus1 = 0;
    int idx_minus2 = 0;

    for (int idx = 1; idx < noOfSteps; ++idx)
    {
        int oneJump = abs(heights[idx] - heights[idx - 1]) + idx_minus1;

        int twoJumps = INT_MAX;
        if (idx > 1)
        {
            twoJumps = abs(heights[idx] - heights[idx - 2]) + idx_minus2;
        }

        currentIdx = min(oneJump, twoJumps);
        idx_minus2 = idx_minus1;
        idx_minus1 = currentIdx;
    }

    return currentIdx;
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int noOfSteps = heights.size();
    cout << solve(noOfSteps, heights);
    return 0;
}