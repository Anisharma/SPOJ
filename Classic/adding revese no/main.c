#include <stdio.h>
#include <stdlib.h>
int rvrs(int c);
int d;
int main()
{
    int a,i=0,j=0,k=0;
    scanf("%d",&a);
    int b[a][2];
    for(i=0;i<a;i++)
    {
        scanf("%d %d",&b[i][0],&b[i][1]);
    }
    for(i=0;i<a;i++)
    {
        j=(rvrs(b[i][0])+rvrs(b[i][1]));
        printf("%d\n",rvrs(j));
    }
    return 0;
}
int rvrs(int c)
{
    d=0;
    while(c>0)
    {
        d=d*10+c%10;
        c=c/10;
    }
    return d;
}
