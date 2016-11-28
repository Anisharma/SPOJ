#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    long long int b[a],c[a],i=0,j=0;
    for(i=0;i<a;i++)
    {
        printf("\n");
        scanf("%lld",&b[i]);
        long long int d;
        long long int e=0;
        for(j=0;j<b[i];j++)
        {
           scanf("%lld",&d);
           e=(e+d)%b[i];
        }
        if(e==0)
        {
            c[i]=1;
        }
    }
    for(i=0;i<a;i++)
    {
        if(c[i]==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
