#include <bits/stdc++.h>
using namespace std;

int util(const int &day, const int &lastActivity, const vector<vector<int>> &pointsChart, vector<vector<int>> &cache)
{
    if (cache[day][lastActivity] != -1)
        return cache[day][lastActivity];

    if (day == 0)
    {
        int maxPoints = INT_MIN;
        for (int activity = 0; activity < 3; ++activity)
        {
            if (activity != lastActivity)
            {
                maxPoints = max(maxPoints,
                                pointsChart[0][activity]);
            }
        }
        return cache[day][lastActivity] = maxPoints;
    }

    int maxPoints = INT_MIN;
    for (int activity = 0; activity < 3; ++activity)
    {
        if (activity != lastActivity)
        {
            maxPoints = std::max(maxPoints,
                                 pointsChart[day][activity] + util(day - 1, activity, pointsChart, cache));
        }
    }

    return cache[day][lastActivity] = maxPoints;
}

int ninjaTraining(const int CHARTSIZE, vector<vector<int>> &pointsChart)
{
    vector<vector<int>> cache(CHARTSIZE, vector<int>(4, -1));
    return util(CHARTSIZE - 1, 3, pointsChart, cache);
}

int main()
{
    vector<vector<int>> pointsChart = {{10, 40, 70},
                                       {20, 50, 80},
                                       {30, 60, 90}};

    const int CHARTSIZE = pointsChart.size();
    cout << ninjaTraining(CHARTSIZE, pointsChart);
    return 0;
}