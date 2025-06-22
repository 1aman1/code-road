#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	using Node = int;
	vector<vector<Node>> adj;

public:
	Graph(int n)
	{
		adj.resize(n);
	}

	void print() const;
	void addEdge(Node u, Node v);
};

void Graph::print() const
{
	for (size_t i = 0; i < adj.size(); ++i)
	{
		cout << i << ": ";
		for (const auto &neighbours : adj[i])
		{
			cout << neighbours << " ";
		}
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

int main()
{
	Graph graph(6);

	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	graph.addEdge(0, 5);

	graph.addEdge(1, 3);
	graph.addEdge(1, 4);

	graph.addEdge(2, 1);

	graph.addEdge(3, 2);
	graph.addEdge(3, 4);

	graph.addEdge(-3, 4);
	graph.addEdge(-3, -44);
	graph.addEdge(3, 44);

	graph.print();

	return 0;
}