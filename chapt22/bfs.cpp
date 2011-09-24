
#include "graph.hpp"

typedef Graphl<char> Graph;

#include <queue>
using namespace std;

void bfs(Graph & G,int s) {
	/*
	 * color: W, whilte; G, gray; B, black;
	 *
	 * */
	int n=G.vertices.size();
	vector<char> color(n,'W');
	vector<int> d(n);
	vector<int> p(n);

	queue<int> Q;

	color[s]='G';
	Q.push(s);
	while(!Q.empty()) {
		int u=Q.front();
		Q.pop();
		for(list<Edge>::iterator it=G.adj[u].begin();it!=G.adj[u].end();it++) {
			int v=it->to;
			if(color[v]='W') {
				color[v]='G';
				d[v]=d[u]+1;

				Q.push(v);
			}
		}
		color[u]='B';
	}

}

void makeGraph(Graph & G) {

}


int main()
{
	Graph g;
	makeGraph(g);

	return 0;
}
