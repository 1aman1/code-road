#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	vector<vector<int>> adj;

public:
	Graph(int n)
	{
		adj.resize(n);
	}

	void print();
	void add_edge(int u, int v);
};

void Graph::print()
{
	for (int i = 0; i < adj.size(); ++i)
	{
		cout << i << ": ";
		for (const auto &neighbours : adj[i])
		{
			cout << neighbours << " ";
		}
		cout << endl;
	}
}

void Graph::add_edge(int u, int v)
{
	if (u < 0 || u >= adj.size() || v < 0 || v >= adj.size())
	{
		cout << "discarding invalid edge " << u << " -> " << v << endl;
		return;
	}
	adj[u].push_back(v);
}

int main()
{
	Graph go(6);

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	go.add_edge(0, 5);

	go.add_edge(1, 3);
	go.add_edge(1, 4);

	go.add_edge(2, 1);

	go.add_edge(3, 2);
	go.add_edge(3, 4);

	go.add_edge(-3, 4);
	go.add_edge(-3, -44);
	go.add_edge(3, 44);

	go.print();

	return 0;
}