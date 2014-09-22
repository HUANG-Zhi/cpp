#include "graph.h"

void Graph::addEdge(int i,int j){
	assert(i < vcount && j< vcount);
	nodes[i].addNode(j);
	nodes[j].addNode(i);
}

void Graph::display(){
	for(int i = 0; i < vcount; i++){
		for(int j : nodes[i].getAdj()){
			std::cout << "Edge:" << i<< "->" << j << std::endl;
		}
	}
}
