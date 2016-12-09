/*
 *	A simple unweighted path algorithm
 *
 *	Time complexity O(|V| + |E|)
 *
 */

#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
	class DistPath {
	public:
		DistPath(size_t n)
		{
			path.resize(n);
			dist.resize(n);
		}
		
		~DistPath()
		{  }
		
		vector<list<size_t> > path;
		vector<size_t> dist;
	};
	
	Graph(size_t n) : v(n)
	{
		adj.resize(v);
	}

	~Graph()
	{
	}

	/* add an edge to the list */
	void add_edge(size_t node, size_t w)
	{
		adj[node].push_back(w);
	}
	
	/* unweighted_path */
	DistPath unweighted_path(size_t s)
	{
		DistPath dp(v);
		queue<size_t> q;
		std::fill(dp.dist.begin(), dp.dist.end(), SIZE_MAX);
		
		dp.dist[s] = 0;
		q.push(s);
		
		while(!q.empty()) {
			size_t x = q.front();
			q.pop();
			
			list<size_t>::iterator itr = adj[x].begin();
			for(; itr != adj[x].end(); ++itr) {
				/* not reached before */
				if(dp.dist[*itr] == SIZE_MAX) {
					dp.dist[*itr] = dp.dist[x] + 1;
					dp.path[*itr] = dp.path[x];
					dp.path[*itr].push_back(x);
					/* push it to the queue. */
					q.push(*itr);
				}
			}
		}
		
		return dp;
	}		

private:
	size_t v;
	vector<list<size_t> > adj;
};

int main(int argc, char **argv)
{
	const size_t n = 7;
	Graph g(n);
	Graph::DistPath pathx(n);
	
	g.add_edge(0, 1);
	g.add_edge(0, 3);
	g.add_edge(1, 3);
	g.add_edge(1, 4);
	g.add_edge(2, 0);
	g.add_edge(2, 5);
	g.add_edge(3, 2);
	g.add_edge(3, 4);
	g.add_edge(3, 5);
	g.add_edge(3, 6);
	g.add_edge(4, 6);
	g.add_edge(6, 5);

	pathx = g.unweighted_path(2);
	
	size_t vertex = 0;
	for(size_t vertex = 0; vertex < n; ++ vertex) {
		cout << "Vettex " << vertex << ": Path: ";
		for(list<size_t>::iterator itr = pathx.path[vertex].begin(); itr != pathx.path[vertex].end(); ++itr)
			cout << *itr << " ";
		
		cout << "Weight: " << pathx.dist[vertex] << endl;
	}
	
	return 0;
}



