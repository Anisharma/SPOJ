#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    for(i=0;i<10;i++)
    {
        long long int a;
        scanf("%lld",&a);
        if(a==12)
        {
            printf("13\n");
        }
        else if(a<12)
        {
            printf("%lld\n",a);
        }
        else
        {

        }
    }
    return 0;
}
