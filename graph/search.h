# include "graph.h"
# include <deque>
# include <climits>
class DepthFirstSearch
{
private:
	bool * marked;
	int * edgeTo;
	int size;
	int count;
	int src;
	void dfs(Graph g,int s);
public:
	int getCount(){return count;}
	bool getMarked(int t){return (t >= size|| t < 0) ? false : marked[t];}
	DepthFirstSearch(Graph g,int s):count(0){
		src = s;
		size = g.vCount();
		marked = new bool [size];
		edgeTo = new int [size];
		for(int i = 0; i < size; i++){
			marked[i] = false;
			edgeTo[i] = -1;
		} 
		if(s < g.vCount() && s >= 0){
			dfs(g,s);
		}
	};
	bool hasPathTo(int t){return getMarked(t);}
	std::deque<int> pathTo(int t);
	~DepthFirstSearch(){
		delete[] marked;
	};
};

class BreadFirstSearch
{
private:
	static const int INFINITY = INT_MAX;
	bool * marked;
	int * edgeTo;
	int * distTo;
	int size;
	int src;
	void bfs(Graph g,int s);
public:
	int getDistTo(int t){return distTo[t];}
	bool getMarked(int t){return (t >= size|| t < 0) ? false : marked[t];}
	BreadFirstSearch(Graph g,int s){
		src = s;
		size = g.vCount();
		marked = new bool [size];
		edgeTo = new int [size];
		distTo = new int [size];
		for(int i = 0; i < size; i++){
			marked[i] = false;
			edgeTo[i] = -1;
		} 
		if(s < g.vCount() && s >= 0){
			bfs(g,s);
		}
	};
	bool hasPathTo(int t){return getMarked(t);}
	std::deque<int> pathTo(int t);
	~BreadFirstSearch(){
		delete[] marked;
	};

};