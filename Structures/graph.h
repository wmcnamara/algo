
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <unordered_set>

struct GraphNode
{
	int data = 0;
};

bool operator<(const GraphNode& first, const GraphNode& second) { return first.data < second.data; }
bool operator==(const GraphNode& first, const GraphNode& second) { return first.data == second.data; }

using DirectedGraph = std::map<GraphNode, std::vector<GraphNode>>;
using UndirectedGraph = std::map<GraphNode, std::vector<GraphNode>>;
using EdgeList = std::vector<std::pair<GraphNode, GraphNode>>;

/*
	Breadth first print

	Where e is the number of edges, the time complexity is:
	O(e)

*/
void BreadthFirstPrint(DirectedGraph& g)
{
	std::queue<GraphNode> bfsQueue;
	std::unordered_set<GraphNode> visited;

	bfsQueue.push(g.begin()->first);

	while (bfsQueue.size() > 0)
	{
		GraphNode current = bfsQueue.front();
		bfsQueue.pop();

		if (visited.contains(current))
		{
			continue;
		}
		else
		{
			visited.insert(current);
		}

		std::cout << current.data << "\n";


		for (const auto& neighor : g.at(current))
		{
			bfsQueue.push(neighor);
		}

	}
}

UndirectedGraph CreateGraphFromEdgeList(EdgeList list)
{
}


/*
	Recursive depth first print

	Where e is the number of edges, the time complexity is:
	O(e)

*/
void DepthFirstPrint(const DirectedGraph& g, const GraphNode& starter)
{
	std::cout << starter.data << '\n';

	for (const GraphNode neighbor : g.at(starter))
	{
		DepthFirstPrint(g, neighbor);
	}
}

bool HasPathBFS(const DirectedGraph& g, const GraphNode& node)
{
	std::queue<GraphNode> bfsQueue;

	bfsQueue.push(g.begin()->first);

	while (bfsQueue.size() > 0)
	{
		GraphNode current = bfsQueue.front();
		bfsQueue.pop();

		if (current == node)
			return true;

		for (const auto& neighor : g.at(current))
		{
			bfsQueue.push(neighor);
		}
	}

	return false;
}

bool HasPathDFS(const DirectedGraph& g, const GraphNode& current, const GraphNode& nodeToFind)
{
	if (current == nodeToFind)
		return true;

	for (const GraphNode& neighbor : g.at(current))
	{
		if (HasPathDFS(g, neighbor, nodeToFind))
			return true;
	}

	return false;
}

int main()
{
	GraphNode a{ 1 };
	GraphNode b{ 2 };
	GraphNode c{ 3 };
	GraphNode d{ 4 };
	GraphNode e{ 5 };
	GraphNode f{ 6 };

	DirectedGraph graph
	({
		{ a, { b, c } },
		{ b, { d } },
		{ c, { e } },
		{ d, { f } },
		{ e, {  } },
		{ f, {  } }
		});

	DepthFirstPrint(graph, graph.begin()->first);
}