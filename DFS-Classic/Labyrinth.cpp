#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
	int vertices;
	list<int> * adj;
public:
	graph(int v);
	void addEdge(int n, int m);
	int BFS(int s);
    int BFS2(int s);
};
graph::graph(int v){
   this->vertices = v;
   adj = new list<int>[v];
}
void graph::addEdge(int n , int m){
   adj[n].push_back(m);
   adj[m].push_back(n);
}
int graph::BFS(int s){
   int d[vertices],greatest=0,index=0;
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
            index = i;
		}
	}
	return index;
}
int graph::BFS2(int s){
   int d[vertices],greatest=0,index=0;
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
            index = i;
        }
    }
    return greatest;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>0){
    	int rows , colums ,vertices=0;
    	cin>>colums>>rows;
    	char a[rows][colums];
    	int b[rows][colums];
    	for (int i = 0; i < rows; ++i){
    	  for (int j = 0; j < colums; ++j){
    	  	b[i][j] = -1;
    	  }
    	}
    	for (int i = 0; i < rows; ++i){
    		for (int j = 0; j < colums; ++j){
    			cin>>a[i][j];
    			if(a[i][j] == '.'){
    				b[i][j] = vertices;
    				vertices++;
    			}
    		}
    	}
    	graph G(vertices);
    	for (int i = 0; i < rows; ++i){
    	  for (int j = 0; j < colums-1; ++j){
    	  	if(a[i][j]=='.'&&a[i][j+1]=='.'){
    	  		G.addEdge(b[i][j] , b[i][j+1]);
    	  	}
    	  }
    	}
    	for (int i = 0; i < colums; ++i){
    	  for (int j = 0; j < rows-1; ++j){
    	  	if(a[j][i]=='.'&&a[j+1][i]=='.'){
    	  		G.addEdge(b[j][i] , b[j+1][i]);
    	  	}
    	  }
    	}
    	int greatest = G.BFS(0);
    	int highest = G.BFS2(greatest);
    	cout<<"Maximum rope length is "<<highest<<".\n";
    	t--;
    }	
	return 0;
}