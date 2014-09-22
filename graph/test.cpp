#include "search.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Graph g(10);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(0,9);
	g.addEdge(9,5);
	g.display();

	DepthFirstSearch dfs1(g,1);
	cout << "reachable from 1:";
	for(int i = 0; i < g.vCount() ; i++){
		if(dfs1.getMarked(i)){
			cout << i << " ";
		}
	}
	cout << endl;

	DepthFirstSearch dfs2(g,0);
	cout << "reachable from 0:";
	for(int i = 0; i < g.vCount() ; i++){
		if(dfs2.getMarked(i)){
			cout << i << " ";
		}
	}
	cout << endl;

	cout << "path to 5:";
	for(int i: dfs2.pathTo(5)){
		cout << i <<" ";
	}
	cout << endl;

	DepthFirstSearch dfs3(g,20);
	cout << "reachable from 20:";
	for(int i = 0; i < g.vCount() ; i++){
		if(dfs3.getMarked(i)){
			cout << i << " ";
		}
	}
	cout << endl;

	BreadFirstSearch bfs2(g,0);
	cout << "reachable from 0:";
	for(int i = 0; i < g.vCount() ; i++){
		if(bfs2.getMarked(i)){
			cout << i << " ";
		}
	}
	cout << endl;

	cout << "dist to 5:" << bfs2.getDistTo(5) <<endl;

	cout << "path to 5:";
	for(int i: bfs2.pathTo(5)){
		cout << i <<" ";
	}
	cout << endl;
}
