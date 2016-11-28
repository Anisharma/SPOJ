#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int prime(long long int x,long long int y)
{
    long long int i=0,k=0;
    for(i=x;i<=y;i++)
    {
        for(k=2;k<=sqrt(i);k++)
        {
          if(i%k!=0)
          {
            break;
          }
          else
          {
              printf("%lld\n",i);
              continue;
          }
        }

    }
    return 0;
}


int main()
{
    int a,i=0;
    scanf("%d",&a);
    long long int b[a][2];
    for(i=0;i<a;i++)
    {
        scanf("%lld %lld",&b[i][0],&b[i][1]);
    }
    for(i=0;i<a;i++)
    {
        prime(b[i][0],b[i][1]);
        printf("\n");
    }
    return 0;
}
