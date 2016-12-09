/*
 *	A simple breadth first traverse.
 *
 *	Kahn's algorithm, time complexity.
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
	}

	~Graph()
	{
	}

	/* add an edge to the list */
	void add_edge(size_t node, size_t w)
	{
		adj[node].push_back(w);
	}
	
	/* BFS */
	bool breadth_first_traverse(void)
	{
		vector<bool> visited(v);
		queue<size_t> q;

		std::fill(visited.begin(), visited.end(), false);
		
		for(size_t i = 0; i < v; ++i) {
			if(!visited[i]) {

				/* whenever a vertex push to queue should be marked visited! */
				q.push(i);
				visited[i] = true;

				while(!q.empty()) {
					size_t x = q.front();
					q.pop();
					cout << x << " ";

					for(list<size_t>::iterator itr = adj[x].begin(); itr != adj[x].end(); ++itr)
						if(!visited[*itr]) {
							q.push(*itr);
							visited[*itr] = true;
						}
				}
			}
		}

		cout << endl;
	}		

private:
	size_t v;
	vector<list<size_t> > adj;
};

int main(int argc, char **argv)
{
	Graph g(5);
	g.add_edge(0, 3);
	g.add_edge(0, 4);
	g.add_edge(3, 1);
	g.add_edge(3, 2);
	g.add_edge(4, 1);

	g.breadth_first_traverse();

	return 0;
}



