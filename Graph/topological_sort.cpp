/*
 *	A simple topological sort for DAG.
 *
 *	Kahn's algorithm, time complexity O(V + E)
 *
 */

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
	Graph(size_t n) : v(n)
	{
		adj.resize(v);
		indegree.resize(v);
		
		std::fill(indegree.begin(), indegree.end(), 0);
	}

	~Graph()
	{
	}

	/* add an edge to the list */
	void add_edge(int node, int w)
	{
		adj[node].push_back(w);
		++indegree[w];
	}
	
	/* topological sort */
	bool topological_sort(void)
	{
		size_t cnt = 0;
		queue<int> q;
		for(size_t i = 0; i < v; ++i) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}
		
		while(!q.empty()) {
			int node = q.front();
			q.pop();		
			std::cout << node << " ";
			++cnt;

			list<int>::iterator beg = adj[node].begin();
			for(; beg != adj[node].end(); ++beg)
				if(0 == (--indegree[*beg]))
					q.push(*beg);
		}
		
		cout << flush;
		/* not DAG */
		if(cnt < v)
			return false;
		else return true;
	}

private:
	size_t v;
	vector<list<int> > adj;
	/* indegree is 0 */
	vector<size_t> indegree;
};

int main(int argc, char **argv)
{
	Graph g(6);
	g.add_edge(0, 1);
	g.add_edge(1, 2);
	g.add_edge(2, 3);
	g.add_edge(3, 4);
	g.add_edge(4, 5);
	
	g.topological_sort();
	cout << endl;

	return 0;
}



