/*
 *	A simple topological sort by dfs for DAG.
 *	
 *	Time Complexity = O(V + E)
 *
 */

#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
	Graph(int n) : v(n)
	{
		adj.resize(v);
	}

	~Graph()
	{
	}

	/* add an edge to the list */
	void add_edge(int node, int w)
	{
		adj[node].push_back(w);
	}
	
	/* topological sort */
	bool topological_sort(void)
	{
		stack<int> s;

		vector<bool> visited(v);
		std::fill(visited.begin(), visited.end(), false);

		for(size_t i = 0; i < v; ++i)
			if(!visited[i])
				topological_sort_recursive(i, visited, s);

		while(!s.empty()) {
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << flush;
	}

private:
	int v;
	vector<list<int> > adj;

	void topological_sort_recursive(int node, vector<bool> &visited, stack<int> &s)
	{
		visited[node] = true;
		
		list<int>::iterator itr;
		for(itr = adj[node].begin(); itr != adj[node].end(); ++itr)
			if(!visited[*itr]) topological_sort_recursive(*itr, visited, s);
		
		// results
		s.push(node);
	}
};

int main(int argc, char **argv)
{
	Graph g(6);
	g.add_edge(5, 2);
	g.add_edge(5, 0);
	g.add_edge(4, 0);
	g.add_edge(4, 1);
	g.add_edge(2, 3);
	g.add_edge(3, 1);

	g.topological_sort();
	cout << endl;

	return 0;
}



