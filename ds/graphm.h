/*
 *  图的相邻矩阵表示
 *
*/

#ifndef __INTRO_2_GRAPHM__
#define __INTRO_2_GRAPHM__

#include "graph.h"

class Graphm: public Graph
{
	private:
		int ** matrix;
	public:
		Graphm(int n):Graph(n) {
			int i,j;
			matrix=new int * [n];
			for(i=0;i<n;i++) {
				matrix[i]=new int [n];
				for(j=0;j<n;j++) {
					maxtrix[i][j]=0;
				}
			}
		}

		~Graphm() {
			int i;
			for(i=0;i<numv;i++)
				delete [] matrix[i];
			delete[] matrix;
		}

		Edge FirstEdge(int o) {
			Edge e;
			e.from=o;
			e.to=-1;
			for(int i=0;i<numv;i++) {
				if(matrix[o][i]!=0) {
					e.to=i;
					e.weight=matrix[o][i];
					break;
				}
			}
			return e;
		}
		
		Edge NextEdge(Edge edge) {
			Edge e;
			e.from=edge.from;
			e.to=-1;
			for(int i=e.to+1;i<numv;i++)
				if(matrix[e.from][i]!=0) {
					e.to=i;
					e.weight=matrix[e.from][i];
					break;
				}
		}

		void setEdge(int f,int t,int w) {
			matrix[f][t]=w;
		}

		void delEdge(int f,int t) {
			matrix[f][t]=0;
		}
};

#define


