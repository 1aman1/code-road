class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int size = grid.size();
        queue<pair<int, int>> nodeQueue;

        for (int eachRow = 0; eachRow < size; ++eachRow)
        {
            for (int eachCol = 0; eachCol < size; ++eachCol)
            {
                if (grid[eachRow][eachCol] == 1)
                {
                    nodeQueue.emplace(eachRow, eachCol);
                }
            }
        }

        int maxDist = -1;

        if (nodeQueue.empty() || nodeQueue.size() == size * size)
        {
            return maxDist;
        }

        vector<int> directions{-1, 0, 1, 0, -1};

        while (not nodeQueue.empty())
        {
            ++maxDist;

            for (int forEachNeighbour = nodeQueue.size(); forEachNeighbour > 0; --forEachNeighbour)
            {
                auto [row, col] = nodeQueue.front();
                nodeQueue.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int eachRow = row + directions[i];
                    int eachCol = col + directions[i + 1];

                    bool withinBounds = 0 <= eachRow && eachRow < size && 0 <= eachCol && eachCol < size;

                    if (withinBounds && grid[eachRow][eachCol] == 0)
                    {
                        grid[eachRow][eachCol] = 1;
                        nodeQueue.emplace(eachRow, eachCol);
                    }
                }
            }
        }
        return maxDist;
    }
};