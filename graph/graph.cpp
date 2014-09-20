# include <vector>
# include <set>
# include <cassert>
# include <iostream>
class Node{
private:
	int value;
	std::set<int> adj;
public:
	Node(int v):value(v){};
	void addNode(int j){
		adj.insert(j);
	}
	std::set<int> getAdj(){return adj;}
};

class Graph{
private:
	const int vcount;
	std::vector<Node> nodes;
public:
	Graph(int v):vcount(v){
		assert(v > 0);
		for(int i = 0; i < v; i++){
			nodes.push_back(Node(i));
		}
	};
	~Graph(){};
	void addEdge(int i,int j);
	void display();
};


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
int main(int argc, char const *argv[])
{
	Graph g(10);
	g.addEdge(1,2);
	g.addEdge(2,1);
	g.addEdge(0,9);
	g.addEdge(2,10);
	g.display();
}
