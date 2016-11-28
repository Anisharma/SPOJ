#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=0;
    scanf("%d",&a);
    long long int b[a],c[a];
    for(i=0;i<a;i++)
    {

        scanf("%lld",&b[i]);
         c[i]=(192+250*(b[i]-1));

    }
    for(i=0;i<a;i++)
    {
        printf("%lld\n",c[i]);
    }
    return 0;
}
