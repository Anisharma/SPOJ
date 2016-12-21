#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>0){
    	int rows , colums ,vertices=0;
    	cin>>colums>>rows;
    	char a[rows][colums];
    	for (int i = 0; i < rows; ++i)
    	{
    		for (int j = 0; j < colums; ++j)
    		{
    			cin>>a[i][j];
    			if(a[i][j] == '.'){
    				vertices++;
    			}
    		}
    	}
    	t--;
    }	
	return 0;
}