#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	using Node = int;
	vector<vector<Node>> adj;

public:
	Graph(int n) { adj.resize(n); }

	void print() const;
	void addEdge(Node u, Node v);
	int count_connected_components();

private:
	void dfs(Node src, vector<bool> &visited);
};

void Graph::print() const
{
	for (size_t i = 0; i < adj.size(); ++i)
	{
		cout << i << ": ";
		for (const auto &neighbour : adj[i])
			cout << neighbour << " ";
		cout << endl;
	}
}

void Graph::addEdge(Node u, Node v)
{
	if (u < 0 || u >= adj.size() || v < 0 || v >= adj.size())
	{
		cerr << "discarding invalid edge " << u << " -> " << v << endl;
		return;
	}
	adj[u].push_back(v);
}

int Graph::count_connected_components()
{
	vector<bool> visited(adj.size(), false);
	int count = 0;

	for (size_t i = 0; i < adj.size(); ++i)
	{
		if (not visited[i])
		{
			dfs(i, visited);
			++count;
		}
	}

	return count;
}

void Graph::dfs(Node src, vector<bool> &visited)
{
	visited[src] = true;
	// cout << src << " ";

	for (const auto &eachConnectedNode : adj[src])
	{
		if (not visited[eachConnectedNode])
		{
			dfs(eachConnectedNode, visited);
		}
	}
}

int main()
{
	Graph graph(6);

	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	// graph.addEdge(0, 5);

	graph.addEdge(1, 3);
	graph.addEdge(1, 4);

	graph.addEdge(2, 1);

	graph.addEdge(3, 2);
	graph.addEdge(3, 4);

	// graph.print();

	cout << graph.count_connected_components() << endl;

	return 0;
}
