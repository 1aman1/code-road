#include <bits/stdc++.h>
using namespace std;

int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }

            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }

        prev.swap(temp);
        temp.clear();
    }

    // The final result is stored in prev[m-1], which represents the destination in the last row
    return prev[m - 1];
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