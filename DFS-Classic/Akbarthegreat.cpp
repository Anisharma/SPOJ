#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph{
	 int vertices;
	list<  int> *adj;
public:
	graph( int v);
	void addEdge( int n, int m);
	void BFS( int s , int *each ,  int strength);
};
graph::graph( int v){
	this->vertices = v;
	adj = new list<  int>[v];
}
void graph::addEdge( int n, int m){
	adj[n].push_back(m);
	adj[m].push_back(n);
}
void graph::BFS( int s, int * each , int strength ){
    bool * visited = new bool[vertices];
     int *d = new  int;
    for ( int i = 0; i < vertices; ++i){
    	visited[i] = false;d[i]=-1;
    }
    list<int> queue;
    queue.push_back(s);
    visited[s] = true;
    d[s]=0;
    each[s] = each[s]+1;
    list< int >::iterator i;
    if (strength==0)
    {
    	return;
    }
    while(!queue.empty()){
       s = queue.front();
       queue.pop_front();
       if(d[s] >= strength ){
       	continue;
       }
       for(i = adj[s].begin();i!=adj[s].end() ; i++){
       	if(!visited[*i]){
            d[*i] = d[s] +1;
            each[*i] = each[*i]+1;
            visited[*i] = true;
            queue.push_back(*i);
       	}
       }   
    }
    //cout<<"\n\n!!--------------------------------------------------------!!\n\n";
}
int main()
{
    int t;
    cin>>t;
    while(t>0){

    	 int a,b,c;
    	cin>>a>>b>>c;
    	graph G(a);
    	for( int i = 0; i < b; ++i){
    		 int n ,m;
    		cin>>n>>m;
    		G.addEdge(n-1 , m-1);
    	}
    	int *each = new int[a];
    	int pole =0;
    	for( int i= 0 ; i <c ; ++i){
    		 int city , strength;
    		cin>>city>>strength;
    		G.BFS(city-1 , each , strength);
    	}


    	for ( int i = 0; i < a; ++i){
    		//cout<<each[i]<<" ";
    	    if(each[i]!=1){
    	    	pole = 1;
    	    }
    	}
    	cout<<"\n";
    	if (pole == 1)
    	{
    		//cout<<"No\n";
    	}else{
    	cout<<"Yes\n";}
    	t--;
    }	
	return 0;
}
