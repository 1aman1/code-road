#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
	using Node = int;
	vector<vector<Node>> adj;

public:
	Graph(int n) { adj.resize(n); }

	void print() const;
	void add_edge(Node u, Node v);
	bool BFS(Node src, Node target);
	void HasPath(Node u, Node v);
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

void Graph::HasPath(Node src, Node target)
{
	if (BFS(src, target))
		cout << "path exists\n";
	else
		cout << "path doesn't exist\n";
}

bool Graph::BFS(Node src, Node target)
{
	vector<bool> visited(adj.size(), false);
	queue<Node> nodeQueue;

	visited[src] = true;
	nodeQueue.push(src);

	while (not nodeQueue.empty())
	{
		Node current = nodeQueue.front();
		nodeQueue.pop();

		if (current == target)
		{
			return true;
		}

		for (const auto &eachConnectedNode : adj[current])
		{
			if (not visited[eachConnectedNode])
			{
				visited[eachConnectedNode] = true;
				nodeQueue.push(eachConnectedNode);
			}
		}
	}
	
	return false;
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

	graph.HasPath(1, 5);

	return 0;
}
