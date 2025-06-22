#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
	using Node = int;
	vector<vector<Node>> adj;

public:
	Graph(int n) { adj.resize(n); }

	void print() const;
	void addEdge(Node u, Node v);
	void dfs();
};

void Graph::print() const
{
	for (size_t i = 0; i < adj.size(); ++i)
	{
		cout << i << ": ";
		for (const auto &eachConnectedNode : adj[i])
			cout << eachConnectedNode << " ";
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

void Graph::dfs()
{
	vector<bool> visited(adj.size(), false);
	stack<Node> nodeStack;

	for (size_t i = 0; i < adj.size(); ++i)
	{
		if (not visited[i])
		{
			nodeStack.push(i);
			visited[i] = true;

			while (not nodeStack.empty())
			{
				Node current = nodeStack.top();
				nodeStack.pop();

				cout << current << " ";

				for (const auto &eachConnectedNode : adj[current])
				{
					if (not visited[eachConnectedNode])
					{
						visited[eachConnectedNode] = true;
						nodeStack.push(eachConnectedNode);
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

	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	// graph.addEdge(0, 5);

	graph.addEdge(1, 3);
	graph.addEdge(1, 4);

	graph.addEdge(2, 1);

	graph.addEdge(3, 2);
	graph.addEdge(3, 4);

	graph.print();

	graph.dfs();

	return 0;
}
