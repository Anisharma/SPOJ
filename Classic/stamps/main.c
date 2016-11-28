#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int a,i;
    scanf("%lld",&a);
    for(i=0;i<a;i++)
    {
       long long int b,c;
        scanf("%lld %lld",&b,&c);
       long long int j=0,k=0,l;
       long long int *d;
        d=malloc(c*sizeof(long long int));
        for(j=0;j<c;j++)
        {
            scanf("%ld",&d[j]);
        }
        for(j=0;j<c;j++)
        {
            for(k=j+1;k<c;k++)
            {
                if(d[j]>d[k])
                {
                    l=d[j];
                    d[j]=d[k];
                    d[k]=l;
                }
            }
        }
        long long int x=0;
        k=0;
        for(j=(c-1);j>=0;j--)
        {
           x=x+d[j];
           ++k;
           if(x>=b)
           {
              break;
           }
        }
        if(k<=j)
        {
            printf("Scenario #%lld:\n",i+1);
            printf("%lld\n\n",k);
        }
        if(k>j)
        {
           printf("Scenario #%lld:\n",i+1);
           printf("impossible\n\n");
        }

    }
    return 0;
}
