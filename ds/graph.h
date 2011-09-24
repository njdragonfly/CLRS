/*
 *  图的抽象数据类型
 *
*/

#ifndef __INTRO_2_ALGO__
#define __INTRO_2_ALGO__

class Edge {
    public:
        int from;
        int to;
        int weight;
        Edge(int f,int t,int w):from(f),to(t),weight(w) {}

};

class Graph
{
    public:
        int numv;
        int nume;

        Graph(int n) {
            numv=n;
            nume=0;
        }

        ~Graph() {
        }

	bool isEdge(Edge e) {
		if(e.to>=0) return true;
		else return false;
	}



        virtual Edge FirstEdge(int i)=0;
        virtual Edge NextEdge(Edge pre)=0;

        virtual void setEdge(int f,int t,int w)=0;
        virtual void delEdge(int f,int t)=0;

};


template <typename T>
class Graph
{
    public:
        int numv;
        int nume;
        T * vertices;
        Graph(int n) {
            numv=n;
            nume=0;
        }
        ~Graph() {
        }

    virtual Edge * FirstEdge(int i)=0;
    virtual Edge * NextEdge(Edge * pre)=0;
    virtual void setEdge(int f,int t,int w)=0;
    virtual void delEdge(int f,int t)=0;
};
#endif
