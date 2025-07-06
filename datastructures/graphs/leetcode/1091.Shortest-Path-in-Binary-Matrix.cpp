class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
            return -1;

        int n = grid.size();
        queue<pair<int, int>> nodeQueue;

        nodeQueue.emplace(0, 0);
        grid[0][0] = 1;

        int pathLength = 0;
        while (not nodeQueue.empty())
        {
            ++pathLength;

            for (int forEachNeighbour = nodeQueue.size(); forEachNeighbour > 0; --forEachNeighbour)
            {
                auto [row, col] = nodeQueue.front();
                nodeQueue.pop();

                if (row == n - 1 && col == n - 1)
                {
                    return pathLength;
                }

                for (int r = row - 1; r <= row + 1; ++r)
                {
                    for (int c = col - 1; c <= col + 1; ++c)
                    {
                        bool withinBounds = 0 <= r && r < n && 0 <= c && c < n;
                        if (withinBounds && grid[r][c] == 0)
                        {
                            grid[r][c] = 1;
                            nodeQueue.emplace(r, c);
                        }
                    }
                }
            }
        }
        return -1;
    }
};