#include <iostream>
using namespace std;
#include <list>
class graph{
	int vertices;
	list<int> *adj;

public:
	graph(int v);
	void addEdge(int n,int m);
	bool BFS(int s);
};
graph::graph(int v){
	this->vertices = v;
	adj = new list<int>[v];
}
void graph::addEdge(int n , int m){
	adj[n].push_back(m);
	adj[m].push_back(n);
}
bool graph::BFS(int s){
	int *color = new int[vertices];
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; ++i){
		visited[i] = false;
		color[i] = 0;
	}
	list<int> queue;
  for(int j=0;j<vertices;j++){
    if(visited[j]== false){
	visited[j] = true;
	color[j] = 1;
    queue.push_back(j);
    list<int>::iterator i;
    while(!queue.empty()){
     s = queue.front();
     queue.pop_front();
     for ( i = adj[s].begin(); i != adj[s].end(); ++i)
     {
          if(!visited[*i]&&(color[*i]==0)){
          	if(color[s]==1){
          		color[*i] = 2;
          	}else if (color[s] ==2){
          		color[*i] = 1;
          	}
          	visited[*i] = true;
          	queue.push_back(*i);
          }else{
          	if(color[*i] == color[s] ){
               return false;
          	}
          }
     }
    } 
  }
  }
   return true;
}
int main(int argc, char const *argv[])
{    
    int t,j=1;
    cin>>t;
    while(t>0){
    	int vertices;
    	long int edges;
    	cin>>vertices>>edges;
    	graph G(vertices);
    	for (long int i = 0; i < edges; ++i){
    		int sources , destination;
    		cin>>sources>>destination;
    		G.addEdge(sources-1 , destination-1);
    	}
    	bool check = G.BFS(0);
    	if(check){
    		cout<<"Scenario #"<<j<<":\n"<<"No suspicious bugs found!\n";
    	}else{
    		cout<<"Scenario #"<<j<<":\n"<<"Suspicious bugs found!\n";
    	}
    	t--;j++;
    }	
	return 0;
}