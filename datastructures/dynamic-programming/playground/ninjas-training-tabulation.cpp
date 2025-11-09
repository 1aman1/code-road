#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> cache(n, vector<int>(4, 0));

    cache[0][0] = max(points[0][1], points[0][2]);
    cache[0][1] = max(points[0][0], points[0][2]);
    cache[0][2] = max(points[0][0], points[0][1]);
    cache[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 3; last >= 0; last--)
        {
            cache[day][last] = 0;
            for (int activity = 0; activity <= 2; activity++)
            {
                if (activity != last)
                {
                    cache[day][last] = max(cache[day][last],
                                           points[day][activity] + cache[day - 1][activity]);
                }
            }
        }
    }

    return cache[n - 1][3];
}

int main()
{
    // Define the points matrix
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};
    int n = points.size(); // Get the number of days
    // Call the ninjaTraining function to find the maximum points and print the result
    cout << ninjaTraining(n, points);
}