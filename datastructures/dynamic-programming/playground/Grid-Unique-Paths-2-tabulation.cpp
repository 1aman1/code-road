#include <bits/stdc++.h>
using namespace std;

int mazeObstaclesUtil(int n, int m, vector<vector<int>> &numberOfWaysCache, vector<vector<int>> &maze)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                numberOfWaysCache[i][j] = 1;
                continue;
            }

            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                numberOfWaysCache[i][j] = 0;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = numberOfWaysCache[i - 1][j];
            if (j > 0)
                left = numberOfWaysCache[i][j - 1];

            numberOfWaysCache[i][j] = up + left;
        }
    }

    return numberOfWaysCache[n - 1][m - 1];
}

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> numberOfWaysCache(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n, m, numberOfWaysCache, maze);
}

int main()
{
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}};

    int n = maze.size();
    int m = maze[0].size();

    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl;
    return 0;
}