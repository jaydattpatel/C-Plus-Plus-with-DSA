// A C++ program to print topological sorting only for DAG(Directed Acyclic Gragh)
#include <bits/stdc++.h>
using namespace std;


class Graph 
{
	int V;  // No. of vertices'
	list<int> *adj; // Pointer to an array containing adjacency listsList
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack); // A function used by topologicalSort

    public:
        Graph(int V);   // Constructor
        void addEdge(int v, int w); // function to add an edge to graph
        void topologicalSort(); // prints a Topological Sort of the complete graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);    // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
	
	visited[v] = true;  // Mark the current node as visited.

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	Stack.push(v);  // Push current vertex to stack which stores result
}


void Graph::topologicalSort()
{
	stack<int> Stack;
	bool* visited = new bool[V];    
	for (int i = 0; i < V; i++) // Mark all the vertices as not visited
		visited[i] = false;

	// Call the recursive helper function to store Topological Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
	
	delete [] visited;
}


int main()
{
	
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	cout<< "Following is a Topological Sort of the given graph: \n";
	g.topologicalSort();

	return 0;
}
