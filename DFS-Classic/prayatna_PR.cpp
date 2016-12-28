#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph{
	int vertex;
	list<int> * adj;
public:
	graph(int v);
	void addEdge(int n , int m);
    int BFS();
};
graph::graph(int v){
    this->vertex = v;
    adj = new list<int>[v];
}
void graph::addEdge(int n , int m ){
	adj[n].push_back(m);
	adj[m].push_back(n);
}
int graph::BFS(){
	int k=0;
	bool *visited = new bool[vertex];
	for (int i = 0; i < vertex; ++i){
		visited[i] = false;
	}
	list<int> queue;
	list<int>::iterator i;
	for(int l=0 ; l<vertex ;l++){
		if(!visited[l]){
			k++;
	   queue.push_back(l);
	     visited[l] = true;
	 while(!queue.empty()){
		int s = queue.front();
		queue.pop_front();
		for(i = adj[s].begin() ; i!=adj[s].end();i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
    }
   } 
   return k;
}
int main(){
	int t;
	cin>>t;
	while(t>0){
		int vertex,edges;
		cin>>vertex;
		graph G(vertex);
		cin>>edges;
        for(int i=0;i<edges;i++){
        	int n,m;
        	cin>>n>>m;
        	G.addEdge(n,m);
        }
        int k = G.BFS();
        cout<<k<<"\n";
		t--;
	}
}