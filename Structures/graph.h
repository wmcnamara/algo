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

using DirectedGraph = std::map<GraphNode, std::vector<GraphNode>>;

void BreadthFirstSearch(DirectedGraph& g)
{
	std::set<GraphNode> visited;
	std::queue<GraphNode> bfsQueue;


}

void DepthFirstSearch(DirectedGraph& g)
{
	std::set<GraphNode> visited;
	std::stack<GraphNode> stack;

	stack.push(g.begin()->first);

	while (stack.size() > 0)
	{
		GraphNode current = stack.top();
		stack.pop();
		std::cout << current.data << "\n";

		for (const auto& neighor : g.at(current))
		{
			stack.push(neighor);
		}

	}
}

void DFSRecursive(DirectedGraph g)
{

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

	DepthFirstSearch(graph);
}