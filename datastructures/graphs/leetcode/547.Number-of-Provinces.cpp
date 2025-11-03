class Solution
{

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int noOfCities = isConnected[0].size();

        if (noOfCities <= 1)
            return 1;

        int noOfProvinces = 0;
        vector<bool> visited(noOfCities, false);

        std::function<void(int)> DFS = [&](int city) -> void
        {
            visited[city] = true;

            for (int neighbour = 0; neighbour < noOfCities; ++neighbour)
            {
                if (not visited[neighbour] &&
                    isConnected[city][neighbour] == 1)
                {
                    DFS(neighbour);
                }
            }
        };

        for (int city = 0; city < noOfCities; ++city)
        {
            if (not visited[city])
            {
                DFS(city);
                ++noOfProvinces;
            }
        }

        return noOfProvinces;
    }
};