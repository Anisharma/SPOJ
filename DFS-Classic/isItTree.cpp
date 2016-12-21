#include <iostream>
using namespace std;
#include <list>
class graph{
  int vertices;
  list<int> * adj;
  bool *visited;
  void DFS(int v/*, bool visited[]*/);
public:
	graph(int v); // constructor
	void addEdge(int v , int w); //v is sourse and w is destination
	void DFSTraversal(int v);
	bool check();
};
graph::graph(int v){
	this->vertices = v;
	adj = new list<int>[v];
	visited = new bool[v];
}
void graph::addEdge(int v,int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void graph::DFS(int v/*, bool *visited*/){
	visited[v] = true;
	

	/*if it was a simple DFS then the below commented code will work */
	list<int>::iterator i;
	for(i = adj[v].begin(); i !=adj[v].end() ; ++i)
	{
		if(!visited[*i]){
			DFS(*i );
		}
	}
}
void graph::DFSTraversal(int v){
   // bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; ++i)
    {
    	visited[i] = false;
    }
    DFS(v);
}
bool graph::check(){
    for(int i=0;i<vertices ; i++){
    	if(visited[i] == false){
    		return false;
    	}
    }
    return true;
}
int main(int argc , char * argv[]){
   int vertices , edges , sources , destination;
   cin>>vertices>>edges;
   graph G(vertices);
   for(int i=0;i<edges;i++){
   	cin>>sources>>destination;
   G.addEdge(sources-1 , destination-1);
   }
   if (vertices != (edges+1))
   {
   	cout<<"NO\n";
   	return 0;
   }
    G.DFSTraversal(0);
   if(G.check()){
   	cout<<"YES\n";
   }else{
   	cout<<"NO\n";
   }
   return 0;
}