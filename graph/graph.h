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
	int vCount(){return vcount;};
	std::set<int> Adj(int s){
		assert(s>=0 && s<vcount);
		return nodes[s].getAdj();
	};
	void display();
};