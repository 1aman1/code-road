#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> cache(n, vector<int>(3, 0));

    cache[0][0] = max(points[0][1], points[0][2]);
    cache[0][1] = max(points[0][0], points[0][2]);
    cache[0][2] = max(points[0][0], points[0][1]);

    for (int day = 1; day < n; day++)
    {
        for (int lastActivity = 0; lastActivity < 3; lastActivity++)
        {
            cache[day][lastActivity] = 0;
            
            for (int task = 0; task < 3; task++)
            {
                if (task != lastActivity)
                {
                    cache[day][lastActivity] = max(cache[day][lastActivity],
                                                   points[day][task] + cache[day - 1][task]);
                }
            }
        }
    }

    return max({cache[n - 1][0], cache[n - 1][1], cache[n - 1][2]});
}

int main()
{
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}};

    int n = points.size();
    cout << ninjaTraining(n, points);
    return 0;
}
