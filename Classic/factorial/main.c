#include <stdio.h>
int no0(int c);
int d;
int main()
{
    int a,i=0,j=0,k=0;
    scanf("%d",&a);
    int b[a];//b[i] will hold the number
    for(i=0;i<a;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<a;i++)
    {
        j=b[i];
        printf("%d\n",no0(j));
    }
    return 0;
}
int no0(int c)//this function will give no of zeros in the number,ex:will find factorial of 5
{
    d=0;
    while(c>0)
    {
        c=c/5;
        d=d+c;
    }
    return d;
}
