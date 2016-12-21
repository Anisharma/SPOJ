#include <iostream>
using namespace std;
#include <list>
class graph{
    int vertices;
    list<int> * adj;
public:
	graph(int v);
	void addEdge(int n , int m);
	int BFS(int s);
	
};
graph::graph(int v){
	this->vertices = v;
	adj = new list<int>[v];
}
void graph::addEdge(int n, int m){
	adj[n].push_back(m);
	adj[m].push_back(n);
}
int graph::BFS(int s){
	int d[vertices],greatest=0;
	bool * visited = new bool[vertices];
	for (int i = 0; i < vertices; ++i){
		visited[i] = false;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	d[s] = 0;
	list<int>::iterator i;
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
				d[*i] = d[s]+1;
			}
		}
	}
	for (int i = 0; i < vertices; ++i)
	{
		if(d[i]>greatest){
			greatest = d[i];
		}
	}
	return greatest;
}
int main(int argv , char * argc[]){
	int nodes;
	cin>>nodes;
	graph G(nodes);
	for (int i = 0; i < nodes-1; ++i){
		int source, destination;
		cin>>source>>destination;
		G.addEdge(source-1,destination-1);
	}
     int farthest = G.BFS(0);
     int output = G.BFS(farthest);
     cout<<output;
	return 0;	
}