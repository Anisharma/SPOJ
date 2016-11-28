#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=0;
    scanf("%d",&a);
    long long int b[a][3],c[a][3];
    for(i=0;i<a;i++)
    {
        scanf("%lld %lld %lld",&b[i][0],&b[i][1],&b[i][2]);
        c[i][0]=(2*b[i][2])/(b[i][0]+b[i][1]);
        c[i][2]=(b[i][1]-b[i][0])/(c[i][0]-5);
        c[i][1]=b[i][0]-2*c[i][2];
    }
    for(i=0;i<a;i++)
    {
        printf("%lld\n",c[i][0]);
         long long int j=0;
         for(j=0;j<c[i][0];j++)
         {
             printf("%lld ",(c[i][1]+j*c[i][2]));
         }
         printf("\n");
    }
    return 0;
}
