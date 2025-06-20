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
	void add_edge(Node u, Node v);
	void DFS();

private:
	void DFSHelper(Node src, vector<bool> &visited);
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

void Graph::add_edge(Node u, Node v)
{
	if (u < 0 || u >= adj.size() || v < 0 || v >= adj.size())
	{
		cerr << "discarding invalid edge " << u << " -> " << v << endl;
		return;
	}
	adj[u].push_back(v);
}

void Graph::DFS()
{
	vector<bool> visited(adj.size(), false);

	for (size_t i = 0; i < adj.size(); ++i)
	{
		if (not visited[i])
		{
			DFSHelper(i, visited);
		}
	}
	cout << "\n";
}

void Graph::DFSHelper(Node src, vector<bool> &visited)
{
	visited[src] = true;
	cout << src << " ";

	for (const auto &eachConnectedNode : adj[src])
	{
		if (not visited[eachConnectedNode])
		{
			DFSHelper(eachConnectedNode, visited);
		}
	}
}

int main()
{
	Graph graph(6);

	graph.add_edge(0, 1);
	graph.add_edge(0, 4);
	// graph.add_edge(0, 5);

	graph.add_edge(1, 3);
	graph.add_edge(1, 4);

	graph.add_edge(2, 1);

	graph.add_edge(3, 2);
	graph.add_edge(3, 4);

	graph.print();

	graph.DFS();

	return 0;
}
