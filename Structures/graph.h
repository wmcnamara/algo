//Weston McNamara
//Problem 6 https://projecteuler.net/problem=6

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>

struct GraphNode
{
	int data = 0;
};

bool operator<(const GraphNode& first, const GraphNode& second) { return first.data < second.data; }
bool operator==(const GraphNode& first, const GraphNode& second) { return first.data == second.data; }

using DirectedGraph = std::map<GraphNode, std::vector<GraphNode>>;

/*
	Breadth first print

	Where n is the number of nodes and m is the number of edges, the time complexity is:
	O(n + m)

*/
void BreadthFirstPrint(DirectedGraph& g)
{
	std::queue<GraphNode> bfsQueue;


	bfsQueue.push(g.begin()->first);

	while (bfsQueue.size() > 0)
	{
		GraphNode current = bfsQueue.front();
		bfsQueue.pop();

		std::cout << current.data << "\n";

		for (const auto& neighor : g.at(current))
		{
			bfsQueue.push(neighor);
		}

	}
}

/*
	Recursive depth first print

	Where n is the number of nodes and m is the number of edges, the time complexity is:
	O(n + m)

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