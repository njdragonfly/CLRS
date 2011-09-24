
#include "graph.hpp"

#include <vector>

using namespace std;

typedef Graphl<int> Graph;

void dfs_visit(Graph &G, int u,vector<int> &pre,vector<char> &color,int &time,vector<int> &d,vector<int> &f) {
	color[u]='G';
	time+=1;
	d[u]=time;
	for(list<Edge>::iterator it=G.adj[u].begin();it!=G.adj[u].end();it++) {
		int v=it->to;
		if(color[v]='W') {
			pre[v]=u;
			dfs_visit(G,v,pre,color,time,d,f);
		}
	}
	color[u]='B';
	time+=1;
	f[u]=time;

}

void dfs(Graph & G) {

	int numv=G.vertices.size();
	vector<char> color(numv,'W');
	vector<int> d(numv);
	vector<int> f(numv);
	vector<int> pre(numv,-1);
	int time=0;
	for(int i=0;i<numv;i++) {
		if(color[i]=='W') {
			dfs_visit(G,i,pre,color,time,d,f);
		}
	}
}


int main()
{
	return 0;
}
