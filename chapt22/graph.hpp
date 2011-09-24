#ifndef __INTRO_TO_ALGO_GRAPH__
#define __INTRO_TO_ALGO_GRAPH__

class Edge {
    public:
        int from;
        int to;
        int weight;
        Edge(int f,int t,int w):from(f),to(t),weight(w) {}
};

#include <vector>
#include <list>
using namespace std;

template <typename T>
class Graphl {
public:
	vector<T> vertices;
	vector<list<Edge> > adj;
	void setEdge(int f,int t,int w);

	Graphl();
};

template <typename T>
void Graphl<T>::setEdge(int f,int t,int w) {
	/*add or update*/
	Edge e(f,v,w);
	adj[f].push_back(e);
}

template <typename T>
Graphl<T>::Graphl() {
}

#endif
