#include <bits/stdc++.h>
using namespace std;

int mazeObstaclesUtil(int i, int j, vector<vector<int>> &numberOfWaysCache, vector<vector<int>> &maze)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (i > 0 && j > 0 && maze[i][j] == -1)
        return 0;

    if (numberOfWaysCache[i][j] != -1)
        return numberOfWaysCache[i][j];

    int up = mazeObstaclesUtil(i - 1, j, numberOfWaysCache, maze);
    int left = mazeObstaclesUtil(i, j - 1, numberOfWaysCache, maze);

    return numberOfWaysCache[i][j] = up + left;
}

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> numberOfWaysCache(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n - 1, m - 1, numberOfWaysCache, maze);
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