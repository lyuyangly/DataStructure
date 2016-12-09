/*
 *	A simple dijkstra path algorithm
 *
 *	Time complexity O(|V|^2)
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
	/* This class save the result of dijkstra path find. */
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
	
	/* This class is a adjcent vertex contains index and weight. */
	class Avertex {
	public:
		Avertex()
		{}
		Avertex(size_t av, size_t aw) : ver(av), weight(aw)
		{}
		~Avertex()
		{}
		
		size_t ver;
		size_t weight;
	};
	
	Graph(size_t n) : v(n)
	{
		adj.resize(v);
	}

	~Graph()
	{
	}

	/* add an edge to the list */
	void add_edge(size_t vertex, size_t adj_vertex, size_t w)
	{
		adj[vertex].push_back(Avertex(adj_vertex, w));
	}
	
	/* dijkstra path */
	DistPath dijkstra_path(size_t s)
	{
		DistPath dp(v);
		queue<size_t> q;
		std::fill(dp.dist.begin(), dp.dist.end(), SIZE_MAX);
		
		dp.dist[s] = 0;
		q.push(s);
		
		while(!q.empty()) {
			size_t x = q.front();
			q.pop();
			
			for(list<Avertex>::iterator itr = adj[x].begin(); itr != adj[x].end(); ++itr) {
				/* if the cost is least than before, then update it. '<' & '<=' is also ok. */
				if(dp.dist[x] + itr->weight < dp.dist[itr->ver]) {
					dp.dist[itr->ver] = dp.dist[x] + (*itr).weight;
					dp.path[itr->ver] = dp.path[x];
					dp.path[itr->ver].push_back(x);
					/* push it to the queue. */
					q.push(itr->ver);
				}
			}
		}
		
		return dp;
	}		

private:
	size_t v;
	vector<list<Avertex> > adj;
};

int main(int argc, char **argv)
{
	const size_t s = 2;
	const size_t n = 7;
	size_t vertex, adj_vertex, w;
	
	Graph g(n);
	Graph::DistPath pathx(n);
	
	/*
	while(cin >> vertex >> adj_vertex >> w) {
		g.add_edge(vertex, adj_vertex, w);
	}
	*/
	
	g.add_edge(0, 1, 1);
	g.add_edge(0, 3, 6);
	g.add_edge(1, 3, 1);
	g.add_edge(1, 4, 1);
	g.add_edge(2, 0, 1);
	g.add_edge(2, 5, 8);
	g.add_edge(3, 2, 1);
	g.add_edge(3, 4, 1);
	g.add_edge(3, 5, 3);
	g.add_edge(3, 6, 4);
	g.add_edge(4, 6, 1);
	g.add_edge(6, 5, 1);

	pathx = g.dijkstra_path(s);
	
	size_t vertex = 0;
	for(size_t vertex = 0; vertex < n; ++vertex) {
		cout << "Vertex " << s << " to " << vertex << ": Path: ";
		for(list<size_t>::iterator itr = pathx.path[vertex].begin(); itr != pathx.path[vertex].end(); ++itr)
			cout << *itr << "->";
		
		cout << "END    Cost: " << pathx.dist[vertex] << endl;
	}
	
	return 0;
}



