#include<iostream>
#include<stdlib.h>

using namespace std;  


struct node{
	long int key;
  int covered;
	node * next;
};

node * getNode(long int key){  //fn to get new node
    node * newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->next = NULL;
    newNode->covered = 0;
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

    counter1 = vertex[destination].next;
     if(counter1 == NULL){
        vertex[destination].next = getNode(source);
     }
     else{
        while(counter1->next != NULL){
            counter1 = counter1->next;
        }
        counter1->next = getNode(source);
     }  

}


long int Deque(long int *stack , long int * top){
  long int a = stack[*top];
  *top = *top - 1;
  return a;
}

void enque(long int * stack , long int * top , long int add){
    stack[*top+1] = add;
    *top = *top+1;
}


void BFS(node * vertex , long int n , long int city , long int stregth , int * color ,long int * d){
	long int i=0, top;
	long int stack[n];
	for(i=0;i<n;i++){
	    stack[i] = 0;
	 	color[i] = 0;
		d[i] = -1;
	}
	color[city] = 1;
	d[city] = 0;
    top=0;
    stack[top] = city;
    while(top>=0){
    	long int current = Deque(stack , &top);
    	if(stregth < d[current]){
    		continue;
    	}
    	vertex[current].covered = vertex[current].covered +1;
    	node * counter = vertex[current].next;
    	while(counter!=NULL){
    		if(color[counter->key] == 0){
              color[counter->key] = 1;
              d[counter->key] = d[current]+1;
              enque(stack , &top , counter->key);
    		}
    		counter = counter->next;
    	}
    	
    }

}

int main(){
     int t;
     cin>>t;
     while(t>0){
        long int i=0,j=0,n,r,m;
        cin>>n>>r>>m;
        node vertex[n];
        for(i=0;i<n;i++){
        	vertex[i].key = i+1;
        	vertex[i].covered = 0;
        	vertex[i].next = NULL;
        }
        for(i=0;i<r;i++){
        	long int source , destination;
        	cin>>source>>destination;
        	addEdge(vertex , source-1 , destination-1);
        }
        long int d[n];
        int color[n];
        for(j=0;j<m;j++){
        	long int city , strength;
        	cin>>city>>strength;
        	BFS(vertex ,n,city-1 , strength, color,d);
        }
        int pole=0;
        cout<<"\n";
        for (j=0; j < n; ++j)
        {
           // cout<<vertex[j].covered<<"\n";
         if(vertex[j].covered == 0 || vertex[j].covered > 1){
           cout<<"NO\n\n";
          pole =1;
          break;
         }
        }
        if (pole == 0)
        {
          cout<<"YES\n\n";
        }
     	t--;
     }
	return 0;
}