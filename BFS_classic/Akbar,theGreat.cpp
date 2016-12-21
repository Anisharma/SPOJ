#include<iostream>
#include<stdlib.h>
//we have to do BFS and every thing is done 
using namespace std; // node struct for the graph 
struct node{
	long int key;
  int covered;
	node * next;
};
node * getNode(long int key){  //fn to get new node
    node * newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}
void addEdge(node * vertex ,long int source ,long int destination){ // fn to add an edge
     node * counter1 = vertex[source].next;
     if(counter1 == NULL){
     	vertex[source].next = getNode(destination);
     }
     else{
     	while(counter1->next != NULL){
     		counter1 = counter1->next;
     	}
     	counter1->next = getNode(destination);
     }

     node * counter2 = vertex[destination].next;
     if(counter2 == NULL){
     	vertex[destination].next = getNode(source);
     }else{
     	while(counter2->next != NULL){
     		counter2 = counter2->next;
     	}
     	counter2->next = getNode(source);
     }
}
void BFS(node * vertex ,long int s ,long int * d,int * color ,long int n ,int *flag ,long int strength ){ // a simple BFS with slight modifications
   long int i=0;
   long int stack[n],top=0;
   for(i=0;i<n ; i++){
   	stack[i] =0;
   	d[i] = -1;
   	color[i] = 0;
   }
   color[s] = 1;
   d[s] = 0;
   stack[top] = s;

   top++;
   while(top>0){
   	 long int stackObject = stack[top] ;
     vertex[stackObject].covered++; 
   	 top--;
   	 node * counter = vertex[stackObject].next;
   	 if(strength  < d[stackObject]){
       continue;
   	 }
   	 while(counter != NULL){
   	 	if(color[counter->key]==0){
          color[counter->key] = 1;
          d[counter->key] = d[stackObject] +1;
          stack[top] = counter->key;
          top++; 
   	 	}
   	 	color[counter->key] = 2;
   	 }
   }
}
int main(){
     int t,i=0;
     cin>>t;
     for ( i = 0; i < t; ++i)
     {
     long int n ,r ,m , j=0 ,k=0;
       int flag =0;
     cin>>n>>r>>m;
     node vertex[n];
       for (j= 0; j < n; ++j)
        {
     	vertex[j].key = j;
      vertex[j].covered = 0;
     	vertex[j].next = NULL;
        }
        for(j=0;j<r;j++){
        	long int source , destination;
        	cin>>source>>destination;
        	addEdge(vertex , source , destination);
        }
        long int d[n];
        int color[n];
        for(j=0;j<m;j++){
        	long int city , strength;
        	cin>>city>>strength;
          flag = 0;
        	BFS(vertex , city ,d , color ,n,&flag, strength);
        }
        int pole=0;
        for (j= 0; j < n; ++j)
        {
         if(vertex[j].covered == 0 || vertex[j].covered > 1){
          cout<<"NO\n";
          pole =1;
          break;
         }
        }
        if (pole == 0)
        {
          cout<<"YES\n";
        }
     }
	return 0;
}