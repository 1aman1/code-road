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
	void BFS();
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
	if (u < 0 || u >= static_cast<int>(adj.size()) || v < 0 || v >= static_cast<int>(adj.size()))
	{
		cerr << "discarding invalid edge " << u << " -> " << v << endl;
		return;
	}
	adj[u].push_back(v);
}

void Graph::BFS()
{
	vector<bool> visited(adj.size(), false);
	queue<Node> nodeQueue;

	for (size_t i = 0; i < adj.size(); ++i)
	{
		if (not visited[i])
		{
			nodeQueue.push(i);
			visited[i] = true;

			while (not nodeQueue.empty())
			{
				Node current = nodeQueue.front();
				nodeQueue.pop();
				cout << current << " ";

				for (const auto &eachConnectedNode : adj[current])
				{
					if (not visited[eachConnectedNode])
					{
						visited[eachConnectedNode] = true;
						nodeQueue.push(eachConnectedNode);
					}
				}
			}
		}
	}
	cout << "\n";
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

	graph.BFS();

	return 0;
}
