#include <stdio.h>
#include<math.h>
int main()
{
    long long int a;
    int i=0,j=0;
    scanf("%lld",&a);
    for(i=0;i<50;i++)
    {
        if(pow(2,i)==a)
        {
            printf("TAK");
        }
        else
        {
           ++j;
        }
    }
    if(j==50)
    {
        printf("NIE");
    }

    return 0;
}
