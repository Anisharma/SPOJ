#include <iostream>
using namespace std;
#include <list>
class graph{
	int vertices;
	list<int> *adj;

public:
	graph(int v);
	void addEdge(int n,int m);
	void BFS(int s , int each[] , int strength);
};
graph::graph(int v){
	this->vertices = v;
	adj = new list<int>[v];
}
void graph::addEdge(int n , int m){
	adj[n].push_back(m);
	adj[m].push_back(n);
}
void graph::BFS(int s ,int * each , int strength){
	bool *visited = new bool[vertices];
  int * d = new int[vertices];
	for (int i = 0; i < vertices; ++i){
		visited[i] = false;
	  d[i] = -1;
	}
	list<int> queue;
	visited[s] = true;
  d[s]=0;
    each[s] = each[s] + 1;
    if(strength == 0){
      return;
    }
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty()){
     s = queue.front();
     queue.pop_front();
     if(d[s] >= strength){
      continue;
     }
     for ( i = adj[s].begin(); i != adj[s].end(); ++i)
     {
          if(!visited[*i]){
          	visited[*i] = true;
            d[*i] = d[s]+1;
            each[*i] = each[*i]+1;
          	queue.push_back(*i);
          }
     }
    } 
}
int main(int argc, char const *argv[])
{    
    int t;
    cin>>t;
    while(t>0){
    	int vertices;
    	int edges , soilder;
    	cin>>vertices>>edges>>soilder;
    	graph G(vertices);
    	for (int i = 0; i < edges; ++i){
    		int sources , destination;
    		cin>>sources>>destination;
    		G.addEdge(sources-1 , destination-1);
    	}
      int each[vertices],pole = 0;
      for (int i = 0; i < vertices; ++i){
        each[i] = 0;
      }
      for (int i = 0; i < soilder; ++i)
      {
        int city,strength;
        cin>>city>>strength;
        G.BFS(city-1 , each , strength);
      }
    	for (int i = 0; i < vertices; ++i)
      {
        cout<<each[i]<<" ";
        if(each[i] != 1){
          pole = 1;
        }
      }
      cout<<"\n";
    	if(pole){
    		cout<<"No\n";
    	}else{
    		cout<<"Yes\n";
    	}
    	t--;
    }	
	return 0;
}