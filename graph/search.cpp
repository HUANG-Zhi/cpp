# include "search.h"
void DepthFirstSearch::dfs(Graph g,int s){
	count++;
	marked[s] = true;
	for(int j: g.Adj(s)){
		if(!marked[j]) dfs(g,j);
		edgeTo[j] = s;
	}
}
std::deque<int> DepthFirstSearch::pathTo(int t){
	std::deque<int> path;
	if(!hasPathTo(t)) return path;
	for(int x = t; x != src; x = edgeTo[x]){
		path.push_front(x);
	}
	path.push_front(src);
	return path;
}

void BreadFirstSearch::bfs(Graph g,int s){
	std::deque<int> candi;
	for (int i = 0; i < size; ++i)
	{
		distTo[i] = INFINITY;
	}
	
	marked[s] = true;
	distTo[s] = 0;
	candi.push_back(s);
	int cur = -1;
	while(candi.size() > 0){
		cur = candi.front();
		candi.pop_front();
		for(int j: g.Adj(cur)){
			if(!marked[j]){
				marked[j] = true;
				edgeTo[j] = cur;
				distTo[j] = distTo[cur] + 1;
				candi.push_back(j);
			}
		}
	}
}
std::deque<int> BreadFirstSearch::pathTo(int t){
	std::deque<int> path;
	if(!hasPathTo(t)) return path;
	for(int x = t; x != src; x = edgeTo[x]){
		path.push_front(x);
	}
	path.push_front(src);
	return path;
}