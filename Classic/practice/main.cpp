#include <iostream>

using namespace std;

int main()
{
    int i=0,x,j=0;
    cout<<"enter the number : ";
    cin>>x;
    for(i=x;i>0;i--)
    {
        for(j=i;j>0;j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
