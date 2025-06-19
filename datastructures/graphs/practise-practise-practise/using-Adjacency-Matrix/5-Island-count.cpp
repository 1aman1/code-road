#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Graph
{
protected:
    std::vector<std::vector<bool>> graph;
    int row, col;

    void
    buildGraph();

public:
    Graph(int Row, int Col) : row(Row), col(Col) { buildGraph(); }

    ~Graph();

    void
    fill(std::vector<std::vector<int>> &connections);

    void print();
};

Graph::~Graph()
{
    for (auto eachRow = graph.begin(); eachRow != graph.end(); ++eachRow)
    {
        (*eachRow).resize(0);
    }
    graph.resize(0);
}

void Graph::buildGraph()
{
    graph.resize(row);

    for (auto eachRow = graph.begin(); eachRow != graph.end(); ++eachRow)
        (*eachRow).resize(col);
}

void Graph::print()
{
    for (auto eachRow = graph.begin(); eachRow != graph.end(); ++eachRow)
    {
        for (auto Col = (*eachRow).begin(); Col != (*eachRow).end(); ++Col)
        {
            std::cout << *Col << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::fill(std::vector<std::vector<int>> &connections)
{
    for (size_t r = 0; r < connections.size(); ++r)
    {
        graph[connections[r][0]][connections[r][1]] = true;
    }
}

class Solution : public Graph
{
    std::vector<std::vector<bool>> _visited;

public:
    Solution(int Row, int Col) : Graph(Row, Col)
    {
        MarkVisited();
    }

    int
    getIslandCount();

private:
    bool
    ExploreLand(int, int);

    void
    MarkVisited();
};

void Solution::MarkVisited()
{
    _visited.resize(row);

    for (auto eachRow = _visited.begin(); eachRow != _visited.end(); ++eachRow)
        (*eachRow).resize(col);
}

int Solution::getIslandCount()
{
    int total_islands = 0;

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (ExploreLand(r, c))
            {
                ++total_islands;
            }
        }
    }

    return total_islands;
}

bool Solution::ExploreLand(int Row, int Col)
{
    bool rowCheck = 0 <= Row && Row < row;
    bool colCheck = 0 <= Col && Col < col;

    if (!rowCheck || !colCheck)
        return false;

    if (graph[Row][Col] == false)
        return false;

    if (_visited[Row][Col])
        return false;

    _visited[Row][Col] = true;

    ExploreLand(Row + 1, Col);
    ExploreLand(Row - 1, Col);
    ExploreLand(Row, Col + 1);
    ExploreLand(Row, Col - 1);

    return true;
}

int main()
{
    int row = 4;
    int col = 5;

    Solution obj(row, col);

    std::vector<std::vector<int>> connections{
        {0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 1}, {1, 3}, {2, 0}, {2, 1}};

    obj.fill(connections);

    obj.print();

    std::cout << obj.getIslandCount();

    return 0;
}